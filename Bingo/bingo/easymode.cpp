#include <iostream>
#include <time.h>

#define easy 1
#define hard 2
using namespace std;

bool used[26];
int board[25];
int AI[25];

bool rowchk(int n, bool mode);
bool colchk(int n, bool mode);
int easy_sel();
int hard_sel();
int main() {
	srand((unsigned int)time(0));


	for (int i = 0; i < 25; i++) {
		board[i] = i + 1;
		AI[i] = i + 1;
	}
		
	int idx1, idx2, tmp;
	for (int i = 0; i < 100; i++) {
		//player
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		tmp = board[idx1];
		board[idx1] = board[idx2];
		board[idx2] = tmp;

		//AI
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		tmp = AI[idx1];
		AI[idx1] = AI[idx2];
		AI[idx2] = tmp;
	}
	int iAImode;
	//AI���̵��� ����
	while (true) {
		cout << "1. Esay" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ��带 �����ϼ��� : ";
		
		cin >> iAImode;

		if (iAImode >= easy && iAImode <= hard)
			break;
	}

	/*
	AI easy ��� ::  ���� AI ���ڸ�� �� *�� �ٲ��� ���� ���� �� �ϳ� ����
	*/
	bool chk = 0;
	if (iAImode == easy) cout << " :::::::::::::::: EASY MODE :::::::::::::::: " << endl;
	else cout << " :::::::::::::::: HARD MODE :::::::::::::::: " << endl;
	cout << "==============Player==============" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i * 5 + j] != INT_MAX) cout << board[i * 5 + j] << "\t";
			else cout << "*\t";
		}cout << endl;
	}
	cout << "================AI================" << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (AI[i * 5 + j] != INT_MAX) cout << AI[i * 5 + j] << "\t";
			else cout << "*\t";
		}cout << endl;
	}
	while (1) {
		//system("cls");

		if (!chk) {
			cout << "\n1~ 25 �� ���ڸ� �Է��ϼ���(0 : exit)." << endl;

		}
		chk = 0;
		cout << "player�� �����Դϴ�. : ";
		int cinput;
		cin >> cinput;
		if (cinput == 0) {
			cout << "������ �����մϴ�." << endl;
			system("pause");
			return 0;
		}
		if (used[cinput]) {
			cout << "�̹� ������ �����Դϴ�. �ٽ� �������ּ���." << endl;
			chk = 1;
			continue;
		}
		used[cinput] = true;
		for (int i = 0; i < 25; i++) {
			if (board[i] == cinput)
				board[i] = INT_MAX;
			if(AI[i]==cinput)
				AI[i]= INT_MAX;
		}
		cout << "==============Player==============" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (board[i * 5 + j] != INT_MAX) cout << board[i * 5 + j] << "\t";
				else cout << "*\t";
			}cout << endl;
		}
		cout << "\n================AI================" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (AI[i * 5 + j] != INT_MAX) cout << AI[i * 5 + j] << "\t";
				else cout << "*\t";
			}cout << endl;
		}
		int bingo = 0;
		int bingoAI = 0;
		int dchk0 = 0;
		int dchk0_AI = 0;
		int dchk1 = 0;
		int dchk1_AI = 0;
		for (int i = 0; i < 5; i++) {
			bingo += rowchk(i, 0);
			bingo += colchk(i, 0);
			bingoAI += rowchk(i, 1);
			bingoAI += colchk(i, 1);
		}
		for (int i = 0; i < 5; i++) {
			if (board[i * 5 + i] == INT_MAX)
				dchk0++;
			if (board[4 * (i + 1)] == INT_MAX) {
				dchk1++;
			}
			if (AI[i * 5 + i] == INT_MAX)
				dchk0_AI++;
			if (AI[4 * (i + 1)] == INT_MAX) {
				dchk1_AI++;
			}

		}
		if (dchk0 == 5) bingo++;
		if (dchk1 == 5) bingo++;
		if (dchk0_AI == 5) bingoAI++;
		if (dchk1_AI == 5) bingoAI++;

		if (bingo == 4) cout << "<<<<�¸� �ӹ�>>>>" << endl;
		if (bingoAI == 4) cout << "AI�� ������ 4�� �ϼ��Ǿ����ϴ�. �й��ϼ���!" << endl;
		if (bingo >= 5 && bingoAI >= 5) {
			cout << "\n���º�" << endl;
			system("pause");
			return 0;
		}
		if (bingo >= 5) {
			cout << "\n�¸�" << endl;
			system("pause");
			return 0;
		}
		if (bingoAI >= 5) {
			cout << "\n�й�" << endl;
			system("pause");
			return 0;
		}
		int aiinput = iAImode==1? easy_sel():hard_sel();
		cout << "\nAI�� �����Դϴ�. : " <<aiinput<< endl;
		used[aiinput] = true;
		for (int i = 0; i < 25; i++) {
			if (board[i] == aiinput)
				board[i] = INT_MAX;
			if (AI[i] == aiinput)
				AI[i] = INT_MAX;
		}

		cout << "==============Player==============" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (board[i * 5 + j] != INT_MAX) cout << board[i * 5 + j] << "\t";
				else cout << "*\t";
			}cout << endl;
		}
		cout << "\n================AI================" << endl;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (AI[i * 5 + j] != INT_MAX) cout << AI[i * 5 + j] << "\t";
				else cout << "*\t";
			}cout << endl;
		}
		bingo = 0;
		bingoAI = 0;
		dchk0 = 0;
		dchk0_AI = 0;
		dchk1 = 0;
		dchk1_AI = 0;
		for (int i = 0; i < 5; i++) {
			bingo += rowchk(i,0);
			bingo += colchk(i,0);
			bingoAI += rowchk(i, 1);
			bingoAI += colchk(i, 1);
		}
		for (int i = 0; i < 5; i++) {
			if (board[i * 5 + i] == INT_MAX)
				dchk0++;
			if (board[4 * (i + 1)] == INT_MAX) {
				dchk1++;
			}
			if (AI[i * 5 + i] == INT_MAX)
				dchk0_AI++;
			if (AI[4 * (i + 1)] == INT_MAX) {
				dchk1_AI++;
			}

		}
		if (dchk0 == 5) bingo++;
		if (dchk1 == 5) bingo++;
		if (dchk0_AI == 5) bingoAI++;
		if (dchk1_AI == 5) bingoAI++;


		if (bingo >= 5 && bingoAI>=5) {
			cout << "\n���º�" << endl;
			system("pause");
			return 0;
		}
		if (bingo >= 5) {
			cout << "\n�¸�" << endl;
			system("pause");
			return 0;
		}
		if (bingoAI >= 5) {
			cout << "\n�й�" << endl;
			system("pause");
			return 0;
		}
		if (bingo == 4) cout << "<<<<�¸� �ӹ�>>>>" << endl;
		if (bingoAI == 4) cout << "AI�� ������ 4�� �ϼ��Ǿ����ϴ�. �й��ϼ���!" << endl;
	}
}

bool rowchk(int n, bool mode) {
	if (!mode) {
		for (int i = 0; i < 5; i++) {
			if (board[n * 5 + i] != INT_MAX) return false;
		}
	}
	if (mode) {
		for (int i = 0; i < 5; i++) {
			if (AI[n * 5 + i] != INT_MAX) return false;
		}
	}

	return true;
}

bool colchk(int n, bool mode) {
	if (!mode) {
		for (int i = 0; i < 5; i++) {
			if (board[i * 5 + n] != INT_MAX) return false;
		}
	}
	if (mode) {
		for (int i = 0; i < 5; i++) {
			if (AI[i * 5 + n] != INT_MAX) return false;
		}
	}
	return true;
}


int easy_sel(){
	while (1) {
		int pick = rand() % 25+1;
		if (!used[pick]) {
			used[pick] = true;
			return pick;
		}
	}
}
int hard_sel() { return 0; }