// ALOHA 여름 멘토링 중급반 : DP
// 백준 9184번 - 신나는 함수 실행

/*
재귀 돌리면서 dp에 저장해두기!
0 < a,b,c <=20 일 때만 재귀 돌린다
*/


#include <stdio.h>

int dp[21][21][21];

int w(int a, int b, int c) {
	if (dp[a][b][c]) return dp[a][b][c];

	if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}


int main() {
	while (true) {
		int a, b, c, ans;
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;

		// 재귀 돌리기 전에 종료조건 만들어 놓기 (하나라도 0되면 1 리턴하도록)
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++)
				dp[0][i][j] = 1;
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++)
				dp[i][0][j] = 1;
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++)
				dp[i][j][0] = 1;

		// 0~20 일 때만 재귀 돌리기. 아니면 바로 ans값 내기
		if (a <= 0 || b <= 0 || c <= 0) ans = 1;
		// 20보다 클때는 다 w(20, 20, 20) 인데 예제에 값 나옴
		else if (a > 20 || b > 20 || c > 20) ans = 1048576;
		else ans = w(a, b, c);


		printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
	}
	return 0;
}