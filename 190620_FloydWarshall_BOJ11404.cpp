// 백준 11404번 : 플로이드

/*
그냥 완전 기본 플로이드와샬 문젠데
작년에 풀었을 때 틀렸습니다가 떴었다
그래서 다시 풀어봤는데 또 틀렸다
정말 한참 보다가 어이없는 실수를 발견했다
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

		// 같은 경로, 다른 가중치가 들어올 수 있으므로 최솟값으로 갱신
		if (map[a][b] == 0) map[a][b] = c;
		else map[a][b] = min(map[a][b], c);
	}

	// 경로가 없을 경우 INF로 채워놓기
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) map[i][j] = 0;
			else {
				if (map[i][j] == 0) map[i][j] = INF;
			}
		}
	}

	// i시작, k경유, j도착
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				// (i~k) (k~j) 둘 다 경로가 있을 경우 (i~j)도 경로 존재
				// 두 경로 가중치 합이 작을 경우 갱신
				if (map[i][k] && map[k][j]) {
					map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
				}
			}
		}
	}

	// 출력
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			// INF인 경우 경로가 없다는 뜻이므로 0 출력
	///////////////////////// 이거 안 하고 걍 INF 출력해버려서 틀렸었다....
			if (map[i][j] == INF) map[i][j] = 0;
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

	return 0;
}