// ALOHA ���� ���丵 �߱޹� : DP
// ���� 5557�� - 1�г�

/*
dp[i][j] : i��° ������ ����ؼ� j�� ���� ����� ��

arr[0]~arr[i-1] �� �̿��ؼ� j�� �����´�
�׷��� arr[0]~arr[i]�� �̿��ؼ��� j+arr[i] �̳� j-arr[i]�� ���� �� �ִ�
�׷��� dp[i][j+arr[i]], dp[i][j-arr[i]] ���� dp[i-1][j] �� ����
*/


#include <stdio.h>

int n;
int ans; // �������� ������ ���;��ϴ� ��
int arr[110]; // 0 ~ n-2 ĭ�� ��� �̷�� �� �������

long long dp[110][21];
// dp[i][j] : i��° ������ ����ؼ� j�� ���� ����� �� 
// dp[n-2][ans] �� ����!

bool isOK(int t) { return (t >= 0 && t <= 20) ? true : false; }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%d", &arr[i]);
	scanf("%d", &ans);

	dp[0][arr[0]] = 1;

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			// dp[i-1][j]�� 0�̸� (i-1��° �������� j�� ���� �� ������) �о�
			if (dp[i - 1][j]) {
				if (isOK(j + arr[i])) dp[i][j + arr[i]] += dp[i - 1][j];
				if (isOK(j - arr[i])) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	printf("%lld", dp[n - 2][ans]);
	return 0;
}