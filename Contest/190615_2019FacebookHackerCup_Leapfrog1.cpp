// 2019 Facebook Hacker Cup
// 1�� (15) Leapfrog: Ch.1

/*
�� ���ʿ� A�� �ְ� �� �ڿ� B�� .(�����)�� �ִ�
A�� B�� �پ�Ѿ .�� �����Ѵ� (���������� �Ѿ��)
B�� ������ .�̸� �ű� �� �ִ�
A�� ������ ���� B�� 1�� �̻� �־�� �پ���� �� �ִ�
A�� �� �ڿ� ������ �� ������?
*/

/*
A.		�پ���� ���� �����ϱ� �Ұ���
AB.		B�ϳ� �پ������ ����
ABB		������� �����ϱ� �Ұ���
A.BB	ABB. ���� �Űܼ� �پ������ ����
A..BB..B	�Ұ���
A.B..BBB.	A.B.B.BB. ���� �Űܼ� �پ������ ����
AB.......	.�� �ʹ� ���Ƽ� �Ұ���

-> B�� ������ .�� �������� ũ�ų� ������ �����ϴ�!
�̶� .�� 0�̸� �Ұ����ϴ�

A		<< �̷� ���� ������ ����
*/


#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
	//freopen("leapfrog_ch_.txt", "r", stdin);
	//freopen("output.out", "w", stdout);

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
		
		bool ans;

		if (dotnum <= Bnum) ans = true;
		else ans = false;

		if (dotnum == 0) {
			if (Bnum == 0) ans = true;
			else ans = false;
		}


		printf("Case #%d: ", t);
		if (ans) printf("Y\n");
		else printf("N\n");
	}
}