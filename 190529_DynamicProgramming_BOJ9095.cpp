// 백준 9095번 : 1,2,3 더하기


/*
하나 작은 거에 +1 / 둘 작은 거에 +2 / 셋 작은 거에 +3

1 -> 1
2 -> 1+1 / 2
3 -> 1+1+1, 2+1 / 1+2 / 3
4 -> 1+1+1+1, 2+1+1, 1+2+1, 3+1 / 1+1+2, 2+2 / 1+3

그래서 총 개수 : dp[n] = dp[n-1]+dp[n-2]+dp[n-3]
*/


#include <stdio.h>
int dp[1010] = { 0,1,2,4 };

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 4; i <= n; i++) {
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		printf("%d\n", dp[n]);
	}

	return 0;
}