#include <iostream>
#include <time.h>

#define easy 1
#define hard 2
using namespace std;

bool used[26];
int board[25];
int AI[25];
int bingo;
int bingoAI;
int cnt_AI[25];
bool rowchk(int n, bool mode);
bool colchk(int n, bool mode);

void print_board();
int score_chker(int bingo, int bingoAI);
int easy_sel();
int hard_sel();
void cnt_line();
void make_board();
int main() {
	make_board();
	int iAImode;
	//AI���̵��� ����
	while (true) {
		cout << "1. Esay" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ���带 �����ϼ��� : ";

		cin >> iAImode;

		if (iAImode >= easy && iAImode <= hard)
			break;
	}
	cout << endl;
	/*
	AI easy ���� ::  ���� AI ���ڸ��� �� *�� �ٲ��� ���� ���� �� �ϳ� ����
	*/
	bool chk = 0;
	if (iAImode == easy) cout << ":::::::::::: EASY MODE ::::::::::::" << endl;
	else cout << ":::::::::::: HARD MODE ::::::::::::" << endl;
	print_board();
	int cnt = 0;
	while (1) {
		//system("cls");
		cnt++;
		if (!chk) {
			cout << "1~ 25 �� ���ڸ� �Է��ϼ���(0 : exit)." << endl;

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
		print_board();

		cnt_line();
		if (bingo >= 4 || bingoAI >= 4) {
			system("cls");
			cout << "Player�� ���� : " << cinput << endl;
			//cout << "AI�� ���� : " << aiinput << endl;

			if(score_chker(bingo, bingoAI)) print_board();
			else {
				cout << "���� ����" << endl;
				print_board();
				system("pause");
				return 0;
			}
		}
		system("cls");
		int aiinput = iAImode==1? easy_sel():hard_sel();
		cout << "Player�� ���� : " << cinput << endl;
		cout << "AI�� ���� : " <<aiinput<< endl;
		used[aiinput] = true;
		for (int i = 0; i < 25; i++) {
			if (board[i] == aiinput)
				board[i] = INT_MAX;
			if (AI[i] == aiinput)
				AI[i] = INT_MAX;
		}
		cout <<endl<< cnt <<"��° turn ���� :::::::::::::::::::::::" << endl;
		print_board();

		cnt_line();
		if (bingo >= 4 || bingoAI >= 4) {
			system("cls");
			cout << "Player�� ���� : " << cinput << endl;
			cout << "AI�� ���� : " << aiinput << endl;

			if (score_chker(bingo, bingoAI)) {
				cout << endl << cnt << "��° turn ���� :::::::::::::::::::::::" << endl;
				print_board();
			}
			else {
				cout << "���� ����" << endl;
				print_board();
				system("pause");
				return 0;
			}
		}
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
int hard_sel() {
	int cnt_AI2[25] = { 0, };
	int mxb = 0;
	int mxs = 0;
	int pick;
	int idx=0;
	bool ran = rand() % 2;
	if (ran) {
		for (int i = 0; i < 25; ++i) {
			mxb = 0;
			if (AI[i] != INT_MAX) {
				int tmp = AI[i];
				AI[i] = INT_MAX;
				cnt_line();
				cnt_AI[i] = (bingoAI - cnt_AI[i]);//���� �� �� ������

				int s = (i / 5) * 5;
				for (int j = s; j < s + 5; ++j) {
					if (AI[j] == INT_MAX && j != i) {
						cnt_AI2[i]++;
					}
				}
				s = (i % 5);
				for (int j = 0; j < 5; ++j) {

					if (AI[j * 5 + s] == INT_MAX && j * 5 + s != i) cnt_AI2[i]++;
				}
				if ((i / 5) == (i % 5)) {
					for (int j = 0; j < 5; ++j) {
						if (AI[j * 5 + j] == INT_MAX && j * 5 + j != i) cnt_AI2[i]++;
					}
				}
				if (i % 4 == 0 && i != 24 && i != 0) {
					for (int j = 0; j < 5; ++j) {
						if (AI[4 * (j + 1)] == INT_MAX && 4 * (j + 1) != i) cnt_AI2[i]++;
					}
				}

				if (mxb == 0) {
					for (int j = 0; j < 25; j++) {
						if (mxs < cnt_AI2[j]) {
							mxs = cnt_AI2[j];
							pick = tmp;
						}
					}
				}
				else {
					if (cnt_AI[i] >= mxb) {
						if (mxb == cnt_AI[i]) {
							pick = cnt_AI2[i] > cnt_AI2[idx] ? tmp : AI[idx];
						}
						else {
							mxb = cnt_AI[i];
							pick = tmp;
						}
					}
				}
				AI[i] = tmp;
			}
		}
		return pick;
	}
	else {
		for (int i = 24; i >=0; --i) {
			mxb = 0;
			if (AI[i] != INT_MAX) {
				int tmp = AI[i];
				AI[i] = INT_MAX;
				cnt_line();
				cnt_AI[i] = (bingoAI - cnt_AI[i]);//���� �� �� ������

				int s = (i / 5) * 5;
				for (int j = s; j < s + 5; ++j) {
					if (AI[j] == INT_MAX && j != i) {
						cnt_AI2[i]++;
					}
				}
				s = (i % 5);
				for (int j = 0; j < 5; ++j) {

					if (AI[j * 5 + s] == INT_MAX && j * 5 + s != i) cnt_AI2[i]++;
				}
				if ((i / 5) == (i % 5)) {
					for (int j = 0; j < 5; ++j) {
						if (AI[j * 5 + j] == INT_MAX && j * 5 + j != i) cnt_AI2[i]++;
					}
				}
				if (i % 4 == 0 && i != 24 && i != 0) {
					for (int j = 0; j < 5; ++j) {
						if (AI[4 * (j + 1)] == INT_MAX && 4 * (j + 1) != i) cnt_AI2[i]++;
					}
				}

				if (mxb == 0) {
					for (int j = 0; j < 25; j++) {
						if (mxs < cnt_AI2[j]) {
							mxs = cnt_AI2[j];
							pick = tmp;
						}
					}
				}
				else {
					if (cnt_AI[i] >= mxb) {
						if (mxb == cnt_AI[i]) {
							pick = cnt_AI2[i] > cnt_AI2[idx] ? tmp : AI[idx];
						}
						else {
							mxb = cnt_AI[i];
							pick = tmp;
						}
					}
				}
				AI[i] = tmp;
			}
		}
		return pick;
	}
}

void print_board() {
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
	return;
}

int score_chker(int bingo, int bingoAI) {
	if (bingo >= 5 && bingoAI >= 5) {
		cout << "\n���º�" << endl;
		return 0;
	}
	if (bingo >= 5) {
		cout << "\n�¸�" << endl;
		return 0;
	}
	if (bingoAI >= 5) {
		cout << "\n�й�" << endl;
		return 0;
	}
	if (bingo == 4) cout << "<<<<�¸� �ӹ�>>>>" << endl;
	if (bingoAI == 4) cout << "AI�� ������ 4�� �ϼ��Ǿ����ϴ�. �й��ϼ���!" << endl;

	return 1;
}

void cnt_line() {
	bingo = 0;
	bingoAI = 0;
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

	return;
}

void make_board() {
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
	return;
}
