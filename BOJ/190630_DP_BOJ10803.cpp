// ALOHA ���� ���丵 �߱޹� : DP
// ���� 10803�� - ���簢�� �����


/*
������ �ѷ� ���������ϴϱ�
n*m ¥�� -> n-k*m ¥�� + k*m ¥�� (k=1 ~ n-1/2)
	�ƴϸ�  n*m-k ¥�� + n*k ¥�� (k=1 ~ m-1/2)
�� �ɰ���. �� �ȿ��� �ּڰ� dp�� �����صΰ� ��������Ǵµ�

�ƴ� �̷��Ա����ߴ��� �ð��ʰ�... �ٵ� ������ �����̰ھ ���۸��ߴ���
i�� j�� ���̰� Ŭ �� ����ȭ��Ű�� ���� �ִ���
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;

int dp[10010][110];

int get_dp(int i, int j) {
	if (dp[i][j] != INF) return dp[i][j];

	if (i == j) return dp[i][j] = 1;

	/////////////////////////////// ����.. ��....
	/*
	i�� j�� ���� ���� ū ��쿡��, �� ���� ���̰� j�� ���簢���� �̿��� �����ϴ� ���� ȿ�������� �� �� �ִ�.
	����, ������ ����� �����ϸ鼭 �����غ���, ������ ��ȭ���� ��� �ȴ�.
	--> https://blog.leejseo.com/73
	*/
	if (3 * i >= j * j) return dp[i][j] = get_dp(i - j, j) + 1;

	int save = INF;
	for (int k = 1; k <= j / 2; k++) {
		save = min(save, get_dp(i, k) + get_dp(i, j - k));
	}
	for (int k = 1; k <= i / 2; k++) {
		save = min(save, get_dp(k, j) + get_dp(i - k, j));
	}
	return dp[i][j] = min(dp[i][j], save);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = INF;
		}
	}

	printf("%d", get_dp(n, m));
}