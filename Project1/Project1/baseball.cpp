#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

int main() {
	srand((unsigned int)time(0));
	int num[9];
	for (int i = 0; i<9; i++) {
		num[i] = i + 1;
	}
	int idx1;
	int idx2;
	int tmp;
	for (int i = 0; i<100; i++) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		tmp = num[idx1];
		num[idx1] = num[idx2];
		num[idx2] = tmp;
	}
	bool sel_num[9] = { 0, };
	for (int i = 0; i<3; i++) {
		sel_num[num[i]] = true;
	}
	int cnt = 0;
	while (1) {
		int strike = 0;
		int ball = 0;
		bool out = 1;
		int ip[3];
		cout << "Input 3 Number(1~9, 0: exit) : ";
		cnt++;
		cin >> ip[0] >> ip[1] >> ip[2];
		if (ip[0] == 0 || ip[1] == 0 || ip[2] == 0) return 0;
		for (int i = 0; i<3; i++) {
			if (ip[i] != num[i]) break;
			if (i == 2) {
				cout << "Correct ! :: try " << cnt << endl;
				cout << "The answer is : " << num[0] << " " << num[1] << " " << num[2] << endl;
				system("pause");
				return 0;
			}
		}
		if ((ip[0]<0 && ip[0]>9) || (ip[1]<0 && ip[1]>9) || (ip[2]<0 && ip[2]>9)) {
			cout << "Out of number, try again " << endl;
			continue;
		}
		for (int i = 0; i<3; i++) {
			if (ip[i] == num[i]) {
				strike++;
				out = 0;
			}
			else if (sel_num[ip[i]]) {
				ball++;
				out = 0;
			}
		}
		if (out) {
			cout << "Out" << endl;
		}
		else {
			cout << strike << "strike " << ball << "ball" << endl;
		}
	}
	
}