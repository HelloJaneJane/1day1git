// ���� 11404�� : �÷��̵�

/*
�׳� ���� �⺻ �÷��̵�ͼ� ������
�۳⿡ Ǯ���� �� Ʋ�Ƚ��ϴٰ� ������
�׷��� �ٽ� Ǯ��ôµ� �� Ʋ�ȴ�
���� ���� ���ٰ� ���̾��� �Ǽ��� �߰��ߴ�
*/


#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int map[110][110];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		// ���� ���, �ٸ� ����ġ�� ���� �� �����Ƿ� �ּڰ����� ����
		if (map[a][b] == 0) map[a][b] = c;
		else map[a][b] = min(map[a][b], c);
	}

	// ��ΰ� ���� ��� INF�� ä������
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) map[i][j] = 0;
			else {
				if (map[i][j] == 0) map[i][j] = INF;
			}
		}
	}

	// i����, k����, j����
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// (i~k) (k~j) �� �� ��ΰ� ���� ��� (i~j)�� ��� ����
				// �� ��� ����ġ ���� ���� ��� ����
				if (map[i][k] && map[k][j]) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
	}

	// ���
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// INF�� ��� ��ΰ� ���ٴ� ���̹Ƿ� 0 ���
	///////////////////////// �̰� �� �ϰ� �� INF ����ع����� Ʋ�Ⱦ���....
			if (map[i][j] == INF) map[i][j] = 0;
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}