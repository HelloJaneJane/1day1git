// ���� 9095�� : 1,2,3 ���ϱ�


/*
�ϳ� ���� �ſ� +1 / �� ���� �ſ� +2 / �� ���� �ſ� +3

1 -> 1
2 -> 1+1 / 2
3 -> 1+1+1, 2+1 / 1+2 / 3
4 -> 1+1+1+1, 2+1+1, 1+2+1, 3+1 / 1+1+2, 2+2 / 1+3

�׷��� �� ���� : dp[n] = dp[n-1]+dp[n-2]+dp[n-3]
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