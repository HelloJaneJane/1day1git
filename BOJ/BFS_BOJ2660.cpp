// ALOHA ���� ���丵 �߱޹� : �׷��� - Ž�� (BFS, DFS)
// ���� 2660�� - ȸ��̱�


#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int map[55][55];
int score[55];
int visit[55];

int n;

void bfs(int start) {
	queue <pair<int, int>> q;

	q.push({ start,0 });
	visit[start] = 1;

	while (!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();

		// �� �ٸ� ���ƴ��� score�� �ִ����� ����
		score[start] = max(score[start], cnt);

		// now�� i�� ���� �������� �� �ٸ� �߰�
		for (int i = 1; i <= n; i++) {
			if (visit[i] == 0 && map[now][i] == 1) {
				q.push({ i,cnt + 1 });
				visit[i] = 1;
			}
		}
	}
}


int main() {
	scanf("%d", &n);

	while (true) {
		int a, b;
		scanf("%d%d", &a, &b);
		if (a == -1 && b == -1) break;

		// a�� b�� ģ���� map�� 1 �ֱ�
		map[a][b] = map[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		// i�� ȸ���� ������ ��� ���� i���� ���� bfs�� ������
		// bfs ���� ������ visit �迭 �ʱ�ȭ
		for (int a = 0; a <= n; a++) visit[a] = 0;
		bfs(i);
	}

	// score �߿� ���� ���� �� ans ã��
	int ans = score[1];
	for (int i = 2; i <= n; i++) {
		if (ans >= score[i]) ans = score[i];
	}
	// ans�� score�� ���� ȸ�� ��ȣ i�� fin�� ���� 
	vector<int> fin;
	for (int i = 1; i <= n; i++) {
		if (score[i] == ans) fin.push_back(i);
	}

	// ����, ȸ�� ��, ȸ�� ��ȣ ���
	printf("%d %d\n", ans, fin.size());
	for (int i = 0; i < fin.size(); i++) printf("%d ", fin[i]);

	return 0;
}