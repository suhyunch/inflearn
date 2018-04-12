#include <iostream>
#include <time.h>

#include <conio.h>
using namespace std;

bool IsTheAnswer(int iNum[]);
int main() {
	//���� ���� ����

	//���� 5x5, 1~24���� , ���� ������ ĭ�� ����

	srand((unsigned int)time(0));
	int iNum[25] = {  };
	for (int i = 0; i < 24; i++) {
		iNum[i] = i + 1;
	}
	//���� �ǹ� Ư���� ���
	int sidx = 24;
	iNum[24] = INT_MAX;
	//INT_MAX�� �̹� ���ǵ� ��, int�� ǥ���� �� �ִ� �ִ밪

/*	//Shuffle
	int iTmp, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTmp = iNum[idx1];
		iNum[idx1] = iNum[idx2];
		iNum[idx2] = iTmp;
	}
	*/
	int cnt = 0;
	while (true) {

		//������ �迭�� ������ �迭ó�� ���
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iNum[i * 5 + j] == INT_MAX) {
					cout << "*" << "\t";
				}
				else cout << iNum[i * 5 + j] << "\t";

			}cout << endl;
		}

		cout << "w : �� , s : �Ʒ�, a: ����, d:������, q : ����. \n";
		char cinput = _getch();
		//_getch()�Լ��� ���� 1���� �Է¹޴� �Լ�
		//�� �Լ��� Enter�� ġ�� �ʴ��� ���ڸ� ������ ���� �ٷ� �� ���ڸ� ��ȯ�ϰ� ����

		//cin >> cinput;
		//cin�� ���͸� �ľ���!!
		//���͸� ���ĵ� �Ǳ� �ٶ�
		//<conio.h> c����� ���
		//console input output �������,
		//�ܼ�â���� ����� �ϴ� ��ɵ��� �������ִ� �������
	
		if (cinput == 'q' || cinput == 'Q') 
			break;
		
		switch (cinput) {
			case 'w' :
			case 'W': 
				if (sidx > 4) {
					iNum[sidx] = iNum[sidx - 5];
					iNum[sidx - 5] = INT_MAX;
					sidx -= 5;
				}
				break;
			case 's' :
			case 'S' :
				if (sidx < 20) {
					iNum[sidx] = iNum[sidx + 5];
					iNum[sidx + 5] = INT_MAX;
					sidx += 5;
				}
				break;
			case 'a' :
			case 'A' :
				if ((sidx % 5)) {
					iNum[sidx] = iNum[sidx - 1];
					iNum[sidx - 1] = INT_MAX;
					sidx--;
				}
				break;
			case 'd' :
			case 'D' :
				if ((sidx % 5) != 4) {
					iNum[sidx] = iNum[sidx + 1];
					iNum[sidx + 1] = INT_MAX;
					sidx++;
				}
				break;
		}
		cnt++;
		if (IsTheAnswer(iNum)) {
			cout << "Correct  ! \nTry :: " << cnt << endl; 
			bool chk = 1;
			while (chk) {
				cout << "If you want to play NEW GAME, press Y, or quit, press Q.\n";
				char cinput2 = _getch();
				switch (cinput2) {
				case 'y':
				case 'Y':
					cout << "\n------------Let's play NEW GAME!------------\n";
					cnt = 0;
					chk = 0;
					break;
				case 'q':
				case 'Q':
					cout << "������ �����մϴ�. \n"<< endl;
					system("pause");
					return 0;
					break;
				defalt:
					cout << "You put the wrong Key.\n\n" << endl;
					break;
				}
			}

		}
		cout << endl;
	}

	cout << "������ �����մϴ�. \nTry :: " << cnt << endl;
	system("pause");
	return 0;
}

bool IsTheAnswer(int iNum[]) {
	for (int i = 0; i < 24; i++) {
		if (iNum[i] != i + 1) {
			return false;
		}
	}
	return true;
}