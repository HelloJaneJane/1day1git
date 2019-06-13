// 백준 9370번 : 미확인 도착지

/*
한 도착지에 대한 최단경로에 한 간선이 포함 되느냐?
-> 일단 최단경로니까 나는 다익스트라를 쓸 거야

이 때 g-h 간선이 그 최단경로에 들어가는지 알기 위해선
map[g]에서 {h,~} 가 pq에 들어갔는지 를 확인하면 된다!
... 라고 생각했지만 pq에 들어갔어도 다른 값으로 갱신될 수가 있더라

그래서 경로를 쪼개서 다익스트라를 세 번 돌렸다 (시간제한이 3초인 이유인듯)
한 번에 가는 최단경로의 dis값과
경유지를 거쳐가는 최단경로의 dis값들의 합이 같으면
경유지를 거쳤다는 뜻이므로 ㅇㅋ, 다르면 ㄴㄴ

*/


#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

vector<pair<int, int> > map[2010]; // map[a]={b,d}

priority_queue<pair<int, int> > pq; // {-거리,점}
int dis_s[2010]; // s에서 시작해서 각 점까지 가는 최단 경로 거리
int dis_g[2010]; // g에서 시작
int dis_h[2010]; // h에서 시작

int n, m, t, s, g, h;

vector<int> fin; // 도착점들 (순서대로 정렬해놓기)


// 다익스트라 세 번 돌릴 건데 각각 쓰기 귀찮으니까 함수로 만들어버렸다
void djikstra(int k, int dis[]) {
	// 시작점 k, 각 점까지 가는 최단 경로 거리 배열 dis

	dis[k] = 0;
	pq.push({ 0,k });

	// pq에 {-거리, 점} 을 넣어서 제일 작은 거리부터 탐색
	while (!pq.empty()) {
		int now = pq.top().second;		// 지금 보고있는 점
		int nowdis = -pq.top().first;	// 아직까지 거쳐온 거리
		pq.pop();

		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i].first;		// 다음에 갈 점
			int nextdis = map[now][i].second;	// 지금~다음 간선 거리
			
			// dis값 보다 작으면 갱신하고 pq에 넣기
			if (dis[next] >= nowdis + nextdis) { 
				dis[next] = nowdis + nextdis;
				pq.push({ -dis[next],next });
			}
		}
	}
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d%d", &n, &m, &t, &s, &g, &h);

		// 초기화
		for (int i = 1; i <= n; i++) {
			map[i].clear();
			dis_s[i] = dis_g[i] = dis_h[i] = INF;
		}

		// 간선 입력
		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			map[a].push_back({ b,d });
			map[b].push_back({ a,d });
		}

		// 목적지 입력
		fin.clear();
		for (int i = 0; i < t; i++) {
			int x;
			scanf("%d", &x);
			fin.push_back(x);
		}
		// 작은 거부터 출력할 거니까 정렬해놓기
		sort(fin.begin(), fin.end());

		// 시작점 s, 경유1 g, 경유2 h 최단경로 다익스트라
		djikstra(s, dis_s);
		djikstra(g, dis_g);
		djikstra(h, dis_h);

		// s->f ==	s->g + g->h + h->f 면 출력
		//			s->h + h->g + g->f
		for (int i = 0; i < t; i++) {
			int f = fin[i];

			int dis1 = dis_s[f];
			int dis2 = dis_s[g] + dis_g[h] + dis_h[f];
			int dis3 = dis_s[h] + dis_h[g] + dis_g[f];

			if (dis1 == min(dis2, dis3)) printf("%d ", f);
		}
		printf("\n");
	}
}