// ALOHA ���� ���丵 �߱޹� : DP
// ���� 11049�� - ��� ���� ����


/*
dp[i][j] : A_i ~ A_j ��� ������ ���ڰ������� �ּ� Ƚ��

(A_i ~ A_j) �� (A_i ~ A_k) / (A_k+1 ~ A_j) �� �ɰ��� ����ϸ�
p[i-1]*p[k] ¥���� p[k]*p[j] ¥���� ���ϴ� �Ŵϱ�

dp[i][j] = (dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j]) �߿� ���� �� (k�� i���� j-1)
*/


#include <stdio.h>

#define INF 987654321;
int n;

int p[510];			// dimension (��� A_i�� p[i-1]*p[i] ¥��)
int mul[510][510];	// mul[i][j] : A_i ~ A_j ��İ����� ���ڰ������� �ּ� Ƚ��

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