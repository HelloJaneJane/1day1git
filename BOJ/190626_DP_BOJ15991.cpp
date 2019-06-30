// ALOHA 여름 멘토링 중급반 : DP
// 백준 15991번 - 1,2,3 더하기 6


/*
1 : 1
2 : 2 / 1+1
3 : 3 / 1+1+1
4 : 2+2 / 1+2+1, 1+1+1+1
5 : 2+1+2 / 1+3+1, 1+1+1+1+1
6 : 3+3 / 2+2+2, 2+1+1+2 / 1+2+2+1, 1+1+2+1+1, 1+1+1+1+1+1
7 : 3+1+3 / 2+3+2, 2+1+1+1+2 / 1+2+1+2+1, 1+1+3+1+1, 1+1+1+1+1+1+1

dp[n]=dp[n-6]+dp[n-4]+dp[n-2]
*/

#include <stdio.h>

#define ll long long
#define mod 1000000009

ll dp[100010] = { 0,1,2,2,3,3,6 };


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		if (!dp[n]) {
			for (int i = 7; i <= n; i++) {
				if (!dp[i]) dp[i] = (dp[i - 6] + dp[i - 4] + dp[i - 2]) % mod;
			}
		}
		printf("%d\n", dp[n]);
	}
}

