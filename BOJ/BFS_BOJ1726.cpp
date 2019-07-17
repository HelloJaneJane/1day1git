// ALOHA 여름 멘토링 중급반 : 그래프 - 탐색 (BFS, DFS)
// 백준 1726번 - 로봇

/*
bfs 돌려서 탐색한다.
근데 그냥 동서남북 가는 게 아니니까 x+dx[], y+dy[] 하는 부분을 바꿔야해
명령 1. go k -> x,y에 +1, -1 하던걸 +1*k, -1*k 해야함
명령 2. turn dir -> x,y는 그대로 두고 방향 바꾸기

go k 할 때 주의할 점이
내가 가려는 점이 0이면 갈 수 있다!라고 판단하면 안 되고
그 점에 도달하기 전에 1이 있으면 중간에 벽이 가로막고있다는 거니까 패스해야함
*/


#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

#define INF 987654321

int m, n;

int map[105][105];

// 그 '위치'에 그 '방향'으로 방문했는지
// INF면 아직 안 방문 한 거고, 시작점에서 얼마나 걸렸는지 최소 cnt로 갱신
int visit[105][105][5];

typedef struct P {
	int x; // 열 (1~n)
	int y; // 행 (1~m)
	int d; // 방향 (동1 서2 남3 북4)
} P;

P st; // 시작점
P en; // 도착점

// 동1 서2 남3 북4 (0은 패쓰)
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

queue<pair<int, P> > qu;

// 두 구조체가 같은 점인지 판단
bool equal(P P1, P P2) {
	if (P1.x == P2.x && P1.y == P2.y && P1.d == P2.d) return true;
	else return false;
}

// 갈 수 있는 좌표인지 판단
bool isok(P p) {
	if (1 <= p.x && p.x <= n && 1 <= p.y && p.y <= m && !map[p.y][p.x]) return true;
	else return false;
}


int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);

			for (int k = 1; k <= 4; k++) visit[i][j][k] = INF;
		}
	}

	scanf("%d%d%d%d%d%d", &st.y, &st.x, &st.d, &en.y, &en.x, &en.d);

	int ans = INF;
	qu.push({ 0,st });
	visit[st.y][st.x][st.d] = 0;

	// BFS 시작
	while (!qu.empty()) {
		P nowP = qu.front().second;
		int nowCnt = qu.front().first;
		qu.pop();

		// 도착점 en이랑 같아지면 ans 값 내기
		if (equal(nowP, en)) ans = min(ans, nowCnt);


		int toX, toY, toD;
		int toCnt = nowCnt + 1;
		P toP;

		// 명령 1 : go k
		for (int k = 1; k <= 3; k++) {
			toD = nowP.d;
			toX = nowP.x + k * dx[toD];
			toY = nowP.y + k * dy[toD];

			toP = { toX,toY,toD };

			// 중간에 한 번이라도 벽 나오면 더 이상 go k 진행 불가
			if (!isok(toP)) break;

			// toP 점이 갈 수 있는 점이고 더 작은 cnt 값이면 갱신
			if (isok(toP) && visit[toY][toX][toD] > toCnt) {
				qu.push({ toCnt,toP });
				visit[toY][toX][toD] = toCnt;
			}
		}


		// 명령 2 : turn dir
		// 동,서->남,북 : 1,2->3,4  or  남,북->동,서 : 3,4->1,2
		toX = nowP.x;
		toY = nowP.y;

		// 동,서->남  or  남,북->동
		if (nowP.d == 1 || nowP.d == 2) toD = 3;
		else toD = 1;

		toP = { toX,toY,toD };
		if (isok(toP) && visit[toY][toX][toD] > toCnt) {
			qu.push({ toCnt,toP });
			visit[toY][toX][toD] = toCnt;
		}

		// 동,서->북  or  남,북->서
		if (nowP.d == 1 || nowP.d == 2) toD = 4;
		else toD = 2;

		toP = { toX,toY,toD };
		if (isok(toP) && visit[toY][toX][toD] > toCnt) {
			qu.push({ toCnt,toP });
			visit[toY][toX][toD] = toCnt;
		}
	}

	printf("%d", ans);
}

