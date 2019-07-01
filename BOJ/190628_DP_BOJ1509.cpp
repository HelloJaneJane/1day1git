// ALOHA ���� ���丵 �߱޹� : DP
// ���� 1509�� - �Ӹ���� ����

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 987654321

char str[2505];

int dp[2505];
// dp[i] : 0~i �ȿ� �Ӹ���� �ּ� ����

int ispalin[2505][2505];
// ispalin[i][j] : i~j �� �Ӹ��������?
// �ʱ�ȭ : -1 / �Ӹ�����̸� 1, �ƴϸ� 0

bool ispal(int s, int e) {
	if (s > e) return 1;

	if (ispalin[s][e] != -1) return ispalin[s][e];

	if (str[s] != str[e]) return ispalin[s][e] = 0;
	else return ispalin[s][e] = ispal(s + 1, e - 1);
}

int main() {
	scanf("%s", str + 1); // 1���̽��� �Ϸ���
	int l = strlen(str + 1);

	memset(ispalin, -1, sizeof(ispalin));

	for (int i = 1; i <= l; i++) {
		ispalin[i][i] = 1;
		dp[i] = INF;

		for (int j = 1; j <= i; j++) {
			// j~i �� �Ӹ�����̸�
			// [0~i �߿� ����]�� [0~j-1 �߿� ����]+1
			if (ispal(j, i)) {
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}

	printf("%d", dp[l]);
}