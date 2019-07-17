// ALOHA ���� ���丵 �߱޹� : DP
// ���� 9184�� - �ų��� �Լ� ����

/*
��� �����鼭 dp�� �����صα�!
0 < a,b,c <=20 �� ���� ��� ������
*/


#include <stdio.h>

int dp[21][21][21];

int w(int a, int b, int c) {
	if (dp[a][b][c]) return dp[a][b][c];

	if (a < b && b < c) return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}


int main() {
	while (true) {
		int a, b, c, ans;
		scanf("%d%d%d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) break;

		// ��� ������ ���� �������� ����� ���� (�ϳ��� 0�Ǹ� 1 �����ϵ���)
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++)
				dp[0][i][j] = 1;
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++)
				dp[i][0][j] = 1;
		for (int i = 0; i <= 20; i++)
			for (int j = 0; j <= 20; j++)
				dp[i][j][0] = 1;

		// 0~20 �� ���� ��� ������. �ƴϸ� �ٷ� ans�� ����
		if (a <= 0 || b <= 0 || c <= 0) ans = 1;
		// 20���� Ŭ���� �� w(20, 20, 20) �ε� ������ �� ����
		else if (a > 20 || b > 20 || c > 20) ans = 1048576;
		else ans = w(a, b, c);


		printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
	}
	return 0;
}