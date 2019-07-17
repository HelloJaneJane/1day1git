// ALOHA 여름 멘토링 중급반 : 그래프 - 탐색 (BFS, DFS)
// 백준 2660번 - 회장뽑기


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

		// 몇 다리 걸쳤는지 score를 최댓값으로 갱신
		score[start] = max(score[start], cnt);

		// now랑 i가 연결 돼있으면 한 다리 추가
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

		// a랑 b랑 친구면 map에 1 넣기
		map[a][b] = map[b][a] = 1;
	}

	for (int i = 1; i <= n; i++) {
		// i번 회원의 점수를 얻기 위해 i번에 대해 bfs를 돌린다
		// bfs 돌릴 때마다 visit 배열 초기화
		for (int a = 0; a <= n; a++) visit[a] = 0;
		bfs(i);
	}

	// score 중에 제일 작은 값 ans 찾기
	int ans = score[1];
	for (int i = 2; i <= n; i++) {
		if (ans >= score[i]) ans = score[i];
	}
	// ans랑 score가 같은 회원 번호 i를 fin에 저장 
	vector<int> fin;
	for (int i = 1; i <= n; i++) {
		if (score[i] == ans) fin.push_back(i);
	}

	// 점수, 회원 수, 회원 번호 출력
	printf("%d %d\n", ans, fin.size());
	for (int i = 0; i < fin.size(); i++) printf("%d ", fin[i]);

	return 0;
}