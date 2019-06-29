// ALOHA 알고리즘반 8주차 강의 준비
// MCST - Kruskal 알고리즘


/*
데이터가 너무 많아서 간선을 다 만들 수가 없다
min(x좌표차이, y좌표차이, z좌표차이)가 가중치이므로
x로/y로/z로 << 세 번 정렬해서 바로 옆에 있는 거만 간선으로 생각한다



*/

#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int n;

int p[100010];


// 각각 정렬하려고 만든 배열 세 개
pair<int, int> mapX[100010];
pair<int, int> mapY[100010];
pair<int, int> mapZ[100010];

// {-가중치,{시작점,끝점}}
priority_queue<pair<int, pair<int, int> > > pq;

// 각 배열에서 데이터 빼서 pq에 넣음 (세 번)
void pq_push(pair<int, int> map[]) {
	for (int i = 1; i <= n - 1; i++) {
		int u = map[i].second;
		int v = map[i + 1].second;
		int w = map[i].first - map[i + 1].first;
		if (w < 0) w *= -1;
		pq.push({ -w,{u,v} });
	}
}

// 경로 압축하는 재귀 find
int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}


int main() {
	scanf("%d", &n);

	// n개 행성 -> x,y,z 따로 저장
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		mapX[i] = { x,i };
		mapY[i] = { y,i };
		mapZ[i] = { z,i };
	}
	// 각각 정렬
	sort(mapX + 1, mapX + n + 1);
	sort(mapY + 1, mapY + n + 1);
	sort(mapZ + 1, mapZ + n + 1);
	
	// 각각 push
	pq_push(mapX);
	pq_push(mapY);
	pq_push(mapZ);

	// 일단 나의 parent == 나 로 초기화
	for (int i = 1; i <= n; i++) p[i] = i;

	int ans = 0;

	// 가중치 제일 작은 것부터 탐색
	while (!pq.empty()) {
		int w = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;

		a = find(a); // a의 root
		b = find(b); // b의 root

		if (a != b) { // 다른 집합이면 union
			ans += w; // MCST로 선택됨
			p[a] = b;
		}
		pq.pop();
	}

	printf("%d", ans);

}