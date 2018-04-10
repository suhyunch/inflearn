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
	//���� ���̺� ����
	srand((unsigned int)time(0));
	int iPlayer, iAI;

	while (1) {
		cout << "�޴��� �����ϼ���." << endl;
		cout << "1. ����" << endl;
		cout << "2. ����" << endl;
		cout << "3. ��" << endl;
		cout << "4. ����" << endl;
		cin >> iPlayer;

		if (R > iPlayer || iPlayer > RSP_end) {
			cout << "ERROR" << endl;
			system("pause");
			continue;
		}
		else if (iPlayer == RSP_end)
			break;

		//���� ����

		iAI = rand() % 3 + R;
		//3���� ����, R�� �ʱⰪ!!
		//iAI�� 4�� �����ϸ� �ȵ�!

		switch (iAI) {
		case R :
			cout << "AI : ����" << endl;
			break;
		case S :
			cout << "AI : ����" << endl;
			break;
		case P :
			cout << "AI : ��" << endl;
			break;
		}

		int iWin = iPlayer - iAI;

		if (iWin == -1 || iWin == 2) {
			cout << "�÷��̾� ��" << endl;
		}
		else if (iWin == 0) {
			cout << "����" << endl;
		}
		else
			cout << "AI �¸�" << endl;

		system("pause");
	}
}
