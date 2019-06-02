// ALOHA 알고리즘반 8주차 강의 준비


/*
 MCST - Kruskal 알고리즘
*/

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int root[10010];


// root 찾을 때 까지 재귀 돌리기
int find(int x) {
	if (x == root[x]) return x;
	return root[x] = find(root[x]); // 경로 압축
}


// {-가중치,{시작점,끝점}}
priority_queue <pair<int, pair<int, int>>> pq;
// 가중치 절댓값이 작은 게 위에 있도록 정렬
// priority queue는 max heap이니까 큰 수가 위로 올라오므로 -1 곱하면 min heap으로도 활용 가능



int main() {
	int V, E;
	scanf("%d%d", &V, &E);

	// 일단은 나의 parent == 나 라고 초기화
	for (int i = 1; i <= V; i++) {
		root[i] = i;
	}

	int ans = 0; // 최소 비용 값

	while (E--) { // 모든 edge를 pq에 넣어서 정렬
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		pq.push({ -c,{a,b} });
	}

	while (!pq.empty()) { // pq에 있는 모든 edge들 탐색
		int w = -pq.top().first;		// 가중치
		int a = pq.top().second.first;	// 시작점
		int b = pq.top().second.second;	// 끝점

		// root 찾기
		a = find(a);
		b = find(b);

		if (a != b) { // 다른 집합이면
			ans += w; // MCST의 edge로 판단! 가중치만큼 비용 추가
			root[a] = b; // Union 
		}
		// 같은 집합이면 패스하기

		pq.pop();
	}

	printf("%d", ans);
	return 0;
}