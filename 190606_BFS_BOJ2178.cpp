// ���� 2178�� : �̷� Ž��

/*
2���� �迭 �������� ������->���� �ִ� ��ΰ� �� ĭ����?
: DFS || BFS
���� ��� ���� �� �����ϴϱ� BFS ���
*/


#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

// �̷� ���� �迭
// �̵� ������ ��η� +1 �ϱ� -> �� �� ���� ���� ������ �ϴ� ĭ ��
int map[110][110];

// �湮 ���� üũ
int visit[110][110];

// ��ǥ�� pair�� ť�� ���� �ž�
queue<pair<int, int>> q;

// �� ���� Ž�� ���ϰ� �ϴ� ��
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// �Է��� �پ �����ϱ� %1d�� �ޱ�
			scanf("%1d", &map[j][i]);
		}
	}

	// ������ push && �湮 üũ
	q.push({ 1,1 });
	visit[1][1] = 1;


	// ť�� �� ������ BFS ������
	while (!q.empty()) {

		// �� ó�� �� pop�ϸ鼭 ���� �� ���� Ž��
		pair<int, int> save = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			// ���� x : second, Ž���� x : +dx
			int x = save.second + dx[i];

			// ���� y : first, Ž���� y : +dy
			int y = save.first + dy[i];

			// ĭ �ȿ� �ְ� && �湮 �� �߰� && ���� ���� ��
			if (y > 0 && y <= m && x > 0 && x <= n && visit[y][x] == 0 && map[y][x] == 1) {
				// map�� �� +1 ���ְ� �� ��ǥ push && �湮 üũ
				map[y][x] = map[save.first][save.second] + 1;
				q.push({ y,x });
				visit[y][x] = 1;
			}
		}
	}

	printf("%d", map[m][n]);
	return 0;
}