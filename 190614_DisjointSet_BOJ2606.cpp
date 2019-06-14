// 백준 2606번 : 바이러스

/*
DFS BFS 로도 풀 수 있을 것 같고.. 분류에는 플로이드로 돼있는데
나는 유니언파인드로 하고 싶어서 했는데
다섯 번이나 틀렸습니다 거쳐서 겨우 맞음 ㅠㅠ
*/


#include <stdio.h>

int V, E;

int root[105];

int find(int x) {
	if (root[x] == x) return x;
	else return root[x] = find(root[x]);
	///////////////////////////////////
	// else 줄에 'return' 안 써서 계속 틀린 거였다 ^^... 근데 저번에도 이런 적 있었다...
}

int main() {
	scanf("%d%d", &V, &E);

	// 초기화 : 나의 루트는 나
	for (int i = 1; i <= V; i++) root[i] = i;

	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (find(a) != find(b)) {
		// a랑 b가 다른 집합이면 연결 시켜주기
			root[find(a)] = find(b);
		}
	}

	int cnt = 0;
	for (int i = 2; i <= V; i++) {
		// 1이랑 같은 집합에 있는 거 개수 세기
		if (find(i) == find(1)) cnt++;
	}
	printf("%d", cnt);

}