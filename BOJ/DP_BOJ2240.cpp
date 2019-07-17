// ALOHA 여름 멘토링 중급반 : DP
// 백준 2240번 - 자두나무

/*
극악의 반례찾기 ^^..

dp[i][j][k] : 시간 i때 j에 있고 k번 움직였어. 자두 최대 개수는?

i때 0에 있고 k번 움직였어
최댓값 = (i-1때 0에 있었어서 그대로였어) or (i-1때 1에 있었어서 움직였어) 중에 최댓값 + i때 0에서 떨어지는 자두 개수
dp[i][0][k] = max(dp[i-1][0][k],dp[i-1][1][k-1])+map[i][0]

1에 있는 거도 마찬가지!


근데
처음부터 끝까지 계속 0에 있을 때 라던가
시작하자마자 1로 옮길 때 라던가..
생각해야함
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int t, w;

int map[1010][2]; 

int dp[1010][2][31]; // [시간][현재위치][움직인횟수]


int main() {
	scanf("%d%d", &t, &w);

	// 시간 i때 a번 나무에서 자두가 떨어진다
	// 1번에서 떨어지면 [0]이 1, 2번이면 [1]이 1
	for (int i = 1; i <= t; i++) {
		int a;
		scanf("%d", &a);
		map[i][a - 1] = 1;
	}

	// 처음부터 끝까지 0에만 있는 경우
	for (int i = 1; i <= t; i++) {
		dp[i][0][0] = dp[i - 1][0][0] + map[i][0];
	}

	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= i && j <= w; j++) {
			dp[i][0][j] = max(dp[i - 1][1][j - 1], dp[i - 1][0][j]) + map[i][0];
			dp[i][1][j] = max(dp[i - 1][0][j - 1], dp[i - 1][1][j]) + map[i][1];
		}
	}

	int ans = 0;
	// 최대 w번까지 움직일 수 있으니까 0부터 w까지 확인
	for (int i = 0; i <= w; i++) ans = max(ans, dp[t][0][i]);
	for (int i = 0; i <= w; i++) ans = max(ans, dp[t][1][i]);

	printf("%d", ans);

	return 0;
}


/*
printf("\ndp\n");
for (int i = 1; i <= t; i++) {
printf("   t==%d\n", i);
for (int j = 0; j < i; j++) {
printf("dp[%d][0][%d]:%d   ", i, j, dp[i][0][j]);
printf("dp[%d][1][%d]:%d\n", i, j, dp[i][1][j]);
}
printf("\n");
}*/