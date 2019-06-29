// 2019 Facebook Hacker Cup
// 1번 (15) Leapfrog: Ch.1

/*
맨 왼쪽에 A가 있고 그 뒤에 B나 .(빈공간)이 있다
A는 B를 뛰어넘어서 .에 착지한다 (오른쪽으로 넘어간다)
B는 옆에가 .이면 옮길 수 있다
A는 무조건 옆에 B가 1개 이상 있어야 뛰어넘을 수 있다
A가 맨 뒤에 도착할 수 있을까?
*/

/*
A.		뛰어넘을 수가 없으니까 불가능
AB.		B하나 뛰어넘으면 가능
ABB		빈공간이 없으니까 불가능
A.BB	ABB. 으로 옮겨서 뛰어넘으면 가능
A..BB..B	불가능
A.B..BBB.	A.B.B.BB. 으로 옮겨서 뛰어넘으면 가능
AB.......	.이 너무 많아서 불가능

-> B의 개수가 .의 개수보다 크거나 같으면 가능하다!
이때 .이 0이면 불가능하다

A		<< 이런 경우는 가능한 예외
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