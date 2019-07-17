// ALOHA 여름 멘토링 중급반 : DP
// 백준 11049번 - 행렬 곱셈 순서


/*
dp[i][j] : A_i ~ A_j 행렬 곱에서 숫자곱셈연산 최소 횟수

(A_i ~ A_j) 를 (A_i ~ A_k) / (A_k+1 ~ A_j) 로 쪼개서 계산하면
p[i-1]*p[k] 짜리랑 p[k]*p[j] 짜리를 곱하는 거니까

dp[i][j] = (dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]) 중에 작은 거 (k는 i부터 j-1)
*/


#include <stdio.h>

#define INF 987654321;
int n;

int p[510];			// dimension (행렬 A_i는 p[i-1]*p[i] 짜리)
int mul[510][510];	// mul[i][j] : A_i ~ A_j 행렬곱에서 숫자곱셈연산 최소 횟수

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &p[i], &p[i + 1]);
	}

	for (int i = n; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {
			mul[i][j] = INF;

			for (int k = i; k < j; k++) {
				int tmp = mul[i][k] + mul[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (mul[i][j] > tmp) {
					mul[i][j] = tmp;
				}
			}
		}
	}

	printf("%d\n", mul[1][n]);

	return 0;
}