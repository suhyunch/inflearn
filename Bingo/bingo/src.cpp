#include <iostream>
#include <time.h>
using namespace std;

bool used[26];
int board[25];

bool rowchk(int n);
bool colchk(int n);

int main() {
	srand((unsigned int)time(0));


	for (int i = 0; i < 25; i++)
		board[i] = i + 1;

	for (int i = 0; i < 100; i++) {
		int idx1 = rand() % 25;
		int idx2 = rand() % 25;

		int tmp = board[idx1];
		board[idx1] = board[idx2];
		board[idx2] = tmp;
	}
	bool chk = 0;
	while (1) {
		if(!chk) cout << "1~ 25 중 숫자를 입력하세요(0 : exit)." << endl;
		chk = 0;

		int cinput;
		cin >> cinput;
		if (cinput == 0) {
			cout << "게임을 종료합니다." << endl;
			system("pause");
			return 0;
		}
		if (used[cinput]) {
			cout << "이미 선택한 숫자입니다. 다시 선택해주세요." << endl;
			chk = 1;
			continue;
		}
		used[cinput] = true;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (board[i * 5 + j] == cinput)
					board[i * 5 + j] = INT_MAX;

				if(board[i * 5 + j]!=INT_MAX) cout << board[i * 5 + j] << "\t";
				else cout << "*\t";
			}cout << endl;
		}

		int bingo = 0;
		int dchk0 = 0;
		int dchk1 = 0;
		for (int i = 0; i < 5; i++) {
			bingo += rowchk(i);
			bingo += colchk(i);
		}
		for (int i = 0; i < 5; i++) {
			if (board[i * 5 + i] == INT_MAX)
				dchk0++;
			if (board[4 * (i + 1)] == INT_MAX) {
				dchk1++;
			}

		}
		if (dchk0 == 5) bingo++;
		if (dchk1 == 5) bingo++;
		if (bingo >= 5) {
			cout << "WIN!" << endl;
			system("pause");
			return 0;
		}
	}
}

bool rowchk(int n) {
	for (int i = 0; i < 5; i++) {
		if (board[n * 5 + i] != INT_MAX) return false;
	}
	return true;
}

bool colchk(int n) {
	for (int i = 0; i < 5; i++) {
		if (board[i * 5 + n] != INT_MAX) return false;
	}
	return true;
}
