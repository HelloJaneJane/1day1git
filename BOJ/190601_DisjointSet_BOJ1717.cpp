// ALOHA 알고리즘반 8주차 강의 준비


/*
 Disjoint Set - Union=Find 알고리즘
*/

#include <stdio.h>

int n, m;
int p[1000010];


// root 찾을 때 까지 재귀 돌리기
int find(int x) { 
	if (p[x] == x) return x;
	else return p[x] = find(p[x]); // 경로 압축
}

void uni(int a, int b) {
	if (find(a) != find(b)) // 다른 집합에 속하면
		p[find(a)] = find(b); // a의 root를 b의 root에 붙인다
}

int main() {
	scanf("%d%d", &n, &m);

	// 일단은 나의 parent == 나 라고 초기화
	for (int i = 1; i <= n; i++) p[i] = i;

	while (m--) {
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);

		if (cmd) { // 1일 때
			// root가 같으면 YES
			if (find(a) == find(b)) printf("YES\n");
			// 아니면 NO
			else printf("NO\n");
		}
		else { // 0일 때
			// 같은 집합에 속하도록 Union 하기
			uni(a, b);
		}
	}
	return 0;
}