// ALOHA ���� ���丵 �߱޹� : DP
// ���� 2240�� - �ڵγ���

/*
�ؾ��� �ݷ�ã�� ^^..

dp[i][j][k] : �ð� i�� j�� �ְ� k�� ��������. �ڵ� �ִ� ������?

i�� 0�� �ְ� k�� ��������
�ִ� = (i-1�� 0�� �־�� �״�ο���) or (i-1�� 1�� �־�� ��������) �߿� �ִ� + i�� 0���� �������� �ڵ� ����
dp[i][0][k] = max(dp[i-1][0][k],dp[i-1][1][k-1])+map[i][0]

1�� �ִ� �ŵ� ��������!


�ٵ�
ó������ ������ ��� 0�� ���� �� �����
�������ڸ��� 1�� �ű� �� �����..
�����ؾ���
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

int t, w;

int map[1010][2]; 

int dp[1010][2][31]; // [�ð�][������ġ][������Ƚ��]


int main() {
	scanf("%d%d", &t, &w);

	// �ð� i�� a�� �������� �ڵΰ� ��������
	// 1������ �������� [0]�� 1, 2���̸� [1]�� 1
	for (int i = 1; i <= t; i++) {
		int a;
		scanf("%d", &a);
		map[i][a - 1] = 1;
	}

	// ó������ ������ 0���� �ִ� ���
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
	// �ִ� w������ ������ �� �����ϱ� 0���� w���� Ȯ��
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