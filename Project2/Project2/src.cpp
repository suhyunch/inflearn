#include <iostream>
#include <time.h>

#include <conio.h>
using namespace std;

bool IsTheAnswer(int iNum[]);
int main() {
	//숫자 퍼즐 게임

	//퍼즐 5x5, 1~24숫자 , 가장 마지막 칸은 공백

	srand((unsigned int)time(0));
	int iNum[25] = {  };
	for (int i = 0; i < 24; i++) {
		iNum[i] = i + 1;
	}
	//공백 의미 특수값 사용
	int sidx = 24;
	iNum[24] = INT_MAX;
	//INT_MAX는 이미 정의된 값, int로 표현할 수 있는 최대값

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

		//일차원 배열을 이차원 배열처럼 사용
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (iNum[i * 5 + j] == INT_MAX) {
					cout << "*" << "\t";
				}
				else cout << iNum[i * 5 + j] << "\t";

			}cout << endl;
		}

		cout << "w : 위 , s : 아래, a: 왼쪽, d:오른쪽, q : 종료. \n";
		char cinput = _getch();
		//_getch()함수는 문자 1개를 입력받는 함수
		//이 함수는 Enter를 치지 않더라도 문자를 누르는 순간 바로 그 문자를 반환하고 종료

		//cin >> cinput;
		//cin은 엔터를 쳐야함!!
		//엔터를 안쳐도 되길 바람
		//<conio.h> c언어의 헤더
		//console input output 헤더파일,
		//콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일
	
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
					cout << "게임을 종료합니다. \n"<< endl;
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

	cout << "게임을 종료합니다. \nTry :: " << cnt << endl;
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