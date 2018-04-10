#include <iostream>
#include <time.h>
using namespace std;

enum RSP
{ 
	R = 1,
	S,
	P,
	RSP_end
};
int main() {
	//난수 테이블 생성
	srand((unsigned int)time(0));
	int iPlayer, iAI;

	while (1) {
		cout << "메뉴를 선택하세요." << endl;
		cout << "1. 바위" << endl;
		cout << "2. 가위" << endl;
		cout << "3. 보" << endl;
		cout << "4. 종료" << endl;
		cin >> iPlayer;

		if (R > iPlayer || iPlayer > RSP_end) {
			cout << "ERROR" << endl;
			system("pause");
			continue;
		}
		else if (iPlayer == RSP_end)
			break;

		//봇이 선택

		iAI = rand() % 3 + R;
		//3가지 종류, R이 초기값!!
		//iAI가 4를 선택하면 안됨!

		switch (iAI) {
		case R :
			cout << "AI : 바위" << endl;
			break;
		case S :
			cout << "AI : 가위" << endl;
			break;
		case P :
			cout << "AI : 보" << endl;
			break;
		}

		int iWin = iPlayer - iAI;

		if (iWin == -1 || iWin == 2) {
			cout << "플레이어 승" << endl;
		}
		else if (iWin == 0) {
			cout << "비김" << endl;
		}
		else
			cout << "AI 승리" << endl;

		system("pause");
	}
}
