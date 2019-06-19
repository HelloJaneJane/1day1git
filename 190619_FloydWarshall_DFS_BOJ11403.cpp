// ���� 11403�� : ��� ã��

/*
�÷��̵� �ͼ� ���� Ǯ��� �; ����
�ٵ� �о�� DFS�� ���� �� ������?
�ٵ� �ٽ� �����غ��� �׳� ��͸� �����⿣ visit üũ�� ��� �ؾ����� ���� �� �ͼ�

�ϴ� �÷��̵�ͼ��� Ǯ����

�׷��� DFS�� �ٽ� Ǯ��ô�
visit üũ �� �ϰ� �׳� �� ó�� map�迭�� ��������ȴ�
*/


#include <stdio.h>

int n;

bool map[105][105];

void dfs(int start, int now) {
	// map[start][?] �� ä��� dfs
	for (int k = 0; k < n; k++) {
		if (map[now][k] && !map[start][k]) {
			// (now~k)���� �ְ� (start~k)�� ���� ������
			// (start~k)�� üũ�صΰ� dfs �ٽ� ������
			map[start][k] = 1;
			dfs(start, k);
		}
	}
}

int main() {
	scanf("%d", &n);

	// �Է�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	/* �÷��̵� �ͼ� */

	// ���� i, ���� k, ���� j
	for (int k = 0; k < n; k++) { // ��� ������ ������ Ž��
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
	// (i~k), (k~j) �� �� ���� ������ (i~j)�� �� �ִ�
				if (map[i][k] && map[k][j])
					map[i][j] = 1;
			}
		}
	}

	/* DFS */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) dfs(i, j);
			// (i~j) ���� ������ dfs������ (start=i, now=j)
		}
	}

	// ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

}