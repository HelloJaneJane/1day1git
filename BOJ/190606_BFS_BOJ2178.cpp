// 백준 2178번 : 미로 탐색

/*
2차원 배열 지도에서 시작점->끝점 최단 경로가 몇 칸인지?
: DFS || BFS
나는 재귀 별로 안 좋아하니까 BFS 사용
*/


#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;

// 미로 지도 배열
// 이동 가능한 경로로 +1 하기 -> 끝 점 최종 값이 지나야 하는 칸 수
int map[110][110];

// 방문 여부 체크
int visit[110][110];

// 좌표는 pair로 큐에 넣을 거야
queue<pair<int, int>> q;

// 네 방향 탐색 편하게 하는 용
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// 입력이 붙어서 들어오니까 %1d로 받기
			scanf("%1d", &map[j][i]);
		}
	}

	// 시작점 push && 방문 체크
	q.push({ 1,1 });
	visit[1][1] = 1;


	// 큐가 빌 때까지 BFS 돌리기
	while (!q.empty()) {

		// 맨 처음 꺼 pop하면서 걔의 네 방향 탐색
		pair<int, int> save = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			// 원래 x : second, 탐색할 x : +dx
			int x = save.second + dx[i];

			// 원래 y : first, 탐색할 y : +dy
			int y = save.first + dy[i];

			// 칸 안에 있고 && 방문 안 했고 && 길이 있을 때
			if (y > 0 && y <= m && x > 0 && x <= n && visit[y][x] == 0 && map[y][x] == 1) {
				// map에 값 +1 해주고 새 좌표 push && 방문 체크
				map[y][x] = map[save.first][save.second] + 1;
				q.push({ y,x });
				visit[y][x] = 1;
			}
		}
	}

	printf("%d", map[m][n]);
	return 0;
}