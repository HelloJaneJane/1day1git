// ALOHA ���� ���丵 �߱޹� : DP
// ���� 1577�� - ������ ����


#include <stdio.h>
#include <algorithm>
using namespace std;

#define ll long long

ll dp[105][105];
// dp[i][j] : 0,0 ~ i,j ����� ��

int map[105][105];
// a,b ~ a+1,b �����ϸ� [c][d]�� 1
// a,b ~ a,b+1 �����ϸ� [c][d]�� 2
// �� �� �ϸ� 3, �� �ϸ� 0

int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);

	// ���� ���� map�� �Է�
	while (k--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);

		if (d == b) {
			map[max(a, c) + 1][d + 1] |= 1;
		}
		else if (c == a) {
			map[c + 1][max(b, d) + 1] |= 2;
		}
	}

	dp[1][1] = 1;
	for (int i = 1; i <= m + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (i == 1 && j == 1) continue;

			if (map[j][i] == 1) // ���� �� ����. �Ʒ����� �� �� ����
				dp[j][i] = dp[j][i - 1];
			else if (map[j][i] == 2) // �Ʒ� �� ����. ���ʼ��� �� �� ����
				dp[j][i] = dp[j - 1][i];
			else if (map[j][i] == 0) // ���� �� �ϸ�
				dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
			else dp[j][i] = 0; // �� �� �ϸ� ���� �� ��
		}
	}

	printf("%lld", dp[n + 1][m + 1]);
	return 0;
}