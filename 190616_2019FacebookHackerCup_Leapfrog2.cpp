// 2019 Facebook Hacker Cup
// 2번 (15) Leapfrog: Ch.2

/*
맨 왼쪽에 A가 있고 그 뒤에 B나 .(빈공간)이 있다
A는 B를 뛰어넘어서 .에 착지한다 (넘어가는 거 왼쪽 오른쪽 양방향 가능)
B는 옆에가 .이면 옮길 수 있다
A는 무조건 옆에 B가 1개 이상 있어야 뛰어넘을 수 있다
A가 맨 뒤에 도착할 수 있을까?
*/

/*
앞에 Ch.1이랑 똑같다
근데 A..BB..B << 이 경우만 달라진다

A..BB..B
A.B.B..B
AB..B..B
.BA.B..B
.BAB...B
.B.BA..B
..BBA..B	<< 여기서 A를 왼쪽으로 넘기면
.ABB...B	<< . 하나가 맨 왼쪽으로 간다!!
.AB.B..B	 -> A 뒤에 B 개수 == . 개수 니까 가능
.AB.B.B.

정리하면 B가 두 개 이상있으면 .을 A보다 왼쪽으로 옮길 수 있으므로
.의 개수가 많아도 가능하다!!!

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