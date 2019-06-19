// 백준 11403번 : 경로 찾기

/*
플로이드 와샬 문제 풀어보고 싶어서 들어갔다
근데 읽어보니 DFS가 나을 거 같더라?
근데 다시 생각해보니 그냥 재귀를 돌리기엔 visit 체크를 어떻게 해야할지 감이 안 와서

일단 플로이드와샬로 풀었다

그러고 DFS로 다시 풀어봤다
visit 체크 안 하고 그냥 맨 처음 map배열에 덮어씌워버렸다
*/


#include <stdio.h>

int n;

bool map[105][105];

void dfs(int start, int now) {
	// map[start][?] 를 채우는 dfs
	for (int k = 0; k < n; k++) {
		if (map[now][k] && !map[start][k]) {
			// (now~k)길이 있고 (start~k)는 아직 없으면
			// (start~k)에 체크해두고 dfs 다시 돌린다
			map[start][k] = 1;
			dfs(start, k);
		}
	}
}

int main() {
	scanf("%d", &n);

	// 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	/* 플로이드 와샬 */

	// 시작 i, 경유 k, 도착 j
	for (int k = 0; k < n; k++) { // 모든 가능한 경유지 탐색
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
	// (i~k), (k~j) 둘 다 길이 있으면 (i~j)도 길 있다
				if (map[i][k] && map[k][j])
					map[i][j] = 1;
			}
		}
	}

	/* DFS */
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j]) dfs(i, j);
			// (i~j) 길이 있으면 dfs돌린다 (start=i, now=j)
		}
	}

	// 출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}

}