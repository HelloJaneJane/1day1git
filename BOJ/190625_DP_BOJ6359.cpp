// ���� 6359�� - ������ ���

/*
0 : ���
1 : ����

n=1	1
0	0
1	1	-> 1

n=2	1 2
0	0 0
1	1 1
2	1 0	-> 1

n=3	1 2 3
0	0 0 0
1	1 1 1
2	1 0 1
3	1 0 0	-> 1

n=4	1 2 3 4
0	0 0 0 0
1	1 1 1 1
2	1 0 1 0
3	1 0 0 0
4	1 0 0 1	-> 2

n=5	1 2 3 4 5
0	0 0 0 0 0
1	1 1 1 1 1
2	1 0 1 0 1
3	1 0 0 0 1
4	1 0 0 1 1
5	1 0 0 1 0	-> 2

n=6	1 2 3 4 5 6
0	0 0 0 0 0 0
1	1 1 1 1 1 1
2	1 0 1 0 1 0
3	1 0 0 0 1 1
4	1 0 0 1 1 1
5	1 0 0 1 0 1
6	1 0 0 1 0 0	 -> 2

--> �տ��� �״�� ���پ��� �� �� �ٸ� �߰���! 
*/

#include <stdio.h>

int dp[105] = { 0,1 };

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
		// dp[n]�� ���� ������ 1���� n���� �� ä�����־�� ��
		// ���� �� ä���� dp[i]�� bottom up ���� ä���
			if (!dp[i]) {

				// 2���� i������ �� �߿� i�� ���� �������� �ϴ� ���� ���� ����
				int cnt = 0;
				for (int j = 2; j <= i; j++) {
					if (i%j == 0) cnt++;
				}

				// Ȧ�� ���� 0���� �ٲ�Ƿ� ��� -> dp[i-1]�̶� ����
				if (cnt % 2) dp[i] = dp[i - 1];
				// ¦�� ���� 1�̹Ƿ� ���� -> dp[i-1]���� �ϳ� �߰�
				else dp[i] = dp[i - 1] + 1;
			}
		}

		printf("%d\n", dp[n]);
	}
}
