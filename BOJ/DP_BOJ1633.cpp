// ALOHA 여름 멘토링 중급반 : DP
// 백준 1633번 - 최고의 팀 만들기

/* dp

<i==1>
w=1 b=0 : 87
w=0 b=1 : 84
w=0 b=0 : 0

<i==2>
w=2 b=0 : dp[1][1][0]+white[2]=153
w=0 b=2 : dp[1][0][1]+black[2]=162
-
w=1 b=1 : max(dp[1][1][0]+black[2],dp[1][0][1]+white[2])=165
---
w=1 b=0 : max(dp[1][1][0],white[2])=87
w=0 b=1 : max(dp[1][0][1],black[2])=84


<i==3>
w=3 b=0 : dp[2][2][0]+white[3]=239
w=0 b=3 : dp[2][0][2]+black[3]
-
w=2 b=1 : max(dp[2][1][1]+white[3],dp[2][2][0]+black[3])
w=1 b=2 : max(dp[2][0][2]+white[3],dp[2][1][1]+black[3])
---
w=2 b=0 : max(dp[2][2][0],dp[2][1][0]+white[3])
w=1 b=1 : max(dp[2][1][1],dp[2][0][1]+white[3],dp[2][1][0]+black[3])
w=0 b=2 : max(dp[2][0][2],dp[2][0][1]+black[3])

w=1 b=0 : max(dp[2][1][0],white[3])
w=0 b=1 : max(dp[2][0][1],black[3])


<i==4>
w=4 b=0 : dp[3][3][0]+white[4]
w=0 b=4 : dp[3][0][3]+black[4]
-
w=3 b=1 : max(dp[3][2][1]+white[4], dp[3][3][0]+black[4])
w=2 b=2 : max(dp[3][1][2]+white[4], dp[3][2][1]+black[4])
w=1 b=3 : max(dp[3][0][3]+white[4], dp[3][1][2]+black[4])
---
w=3 b=0 : max(dp[3][3][0],dp[3][2][0]+white[4])
w=2 b=1 : max(dp[3][2][1],dp[3][1][1]+white[4],dp[3][2][0]+black[4])
w=1 b=2 : max(dp[3][1][2],dp[3][0][2]+white[4],dp[3][1][1]+black[4])
w=0 b=3 : max(dp[3][0][0],dp[3][0][2]+black[4])

w=2 b=0 : max(dp[3][2][0],dp[3][1][0]+white[4])
w=1 b=1 : max(dp[3][1][1],dp[3][0][1]+white[4],dp[3][1][0]+black[4])
w=0 b=2 : max(dp[3][0][2],dp[3][0][1]+black[4])

w=1 b=0 : max(dp[3][1][0],white[4])
w=0 b=1 : max(dp[3][0][1],black[4])
*/



#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int white[1010];
int black[1010];

int dp[1010][16][16];
// dp[i][w][b] : 1번~i번 선수 중 백 w명, 흑 b명 뽑았을 때 최대 능력치

int main() {

	int n = 1;

	int w, b;
	while (scanf("%d%d", &w, &b) != EOF) {
		white[n] = w;
		black[n] = b;
		n++;
	}
	n--;
	dp[1][1][0] = white[1];
	dp[1][0][1] = black[1];

	for (int i = 2; i <= n; i++) {
		for (int w = 15; w >= 0; w--) {
			for (int b = 15; b >= 0; b--) {
				if (w > i || b > i) continue;

				// 백 0명, 흑 0명 선택 -> 0
				if (w == 0 && b == 0) continue;

				if (w == i && b == 0) dp[i][w][b] = dp[i - 1][w - 1][b] + white[i];
				if (w == 0 && b == i) dp[i][w][b] = dp[i - 1][w][b - 1] + black[i];

				if (w + b == i) dp[i][w][b] = max(dp[i - 1][w - 1][b] + white[i], dp[i - 1][w][b - 1] + black[i]);
				else {
					if (b == 0) dp[i][w][b] = max(dp[i - 1][w][b], dp[i - 1][w - 1][b] + white[i]);
					else if (w == 0) dp[i][w][b] = max(dp[i - 1][w][b], dp[i - 1][w][b - 1] + black[i]);
					else dp[i][w][b] = max(dp[i - 1][w][b], max(dp[i - 1][w - 1][b] + white[i], dp[i - 1][w][b - 1] + black[i]));
				}
			}
		}
	}
	printf("%d", dp[n][15][15]);
}

