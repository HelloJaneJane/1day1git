// 2019 Facebook Hacker Cup
// 2�� (15) Leapfrog: Ch.2

/*
�� ���ʿ� A�� �ְ� �� �ڿ� B�� .(�����)�� �ִ�
A�� B�� �پ�Ѿ .�� �����Ѵ� (�Ѿ�� �� ���� ������ ����� ����)
B�� ������ .�̸� �ű� �� �ִ�
A�� ������ ���� B�� 1�� �̻� �־�� �پ���� �� �ִ�
A�� �� �ڿ� ������ �� ������?
*/

/*
�տ� Ch.1�̶� �Ȱ���
�ٵ� A..BB..B << �� ��츸 �޶�����

A..BB..B
A.B.B..B
AB..B..B
.BA.B..B
.BAB...B
.B.BA..B
..BBA..B	<< ���⼭ A�� �������� �ѱ��
.ABB...B	<< . �ϳ��� �� �������� ����!!
.AB.B..B	 -> A �ڿ� B ���� == . ���� �ϱ� ����
.AB.B.B.

�����ϸ� B�� �� �� �̻������� .�� A���� �������� �ű� �� �����Ƿ�
.�� ������ ���Ƶ� �����ϴ�!!!

*/

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


int main() {
	//freopen("leapfrog_ch_.txt", "r", stdin);
	//freopen("output2.out", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;
		int l = s.length();

		int dotnum = 0;
		int Bnum = 0;
		for (int i = 0; i < l; i++) {
			if (s[i] == 'B') Bnum++;
			if (s[i] == '.') dotnum++;
		}

		bool ans = false;
		if (dotnum <= Bnum) ans = true;
		else {
			if (dotnum == 0) {
				if (Bnum == 0) ans = true;
			}
			else {
				if (Bnum >= 2) ans = true;
			}
		}

		printf("Case #%d: ", t);
		if (ans) printf("Y\n");
		else printf("N\n");
	}
}