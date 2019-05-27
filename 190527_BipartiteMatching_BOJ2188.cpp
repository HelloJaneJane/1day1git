// ALOHA 고급반 7주차 - 네트워크플로우 강의 / 백준 2188번

/*
네트워크플로우를 하기 전에 이분매칭을 알아야함!
: 이분 그래프에서 최대로 몇 개까지 매칭할 수 있는지 dfs로 찾기

1번부터 n번까지 차례로 매칭시킴
겹치는 거 있으면 그 전에 꺼 다른걸로 매칭시킬 수 있는지 확인해봄
안 되면 걔는 매칭 불가. 되면 그렇게 매칭하고 넘어가기
*/


#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n, m; // 1~n을 1~m에 연결

vector<int> map[210]; // 간선 저장해두는 인접리스트

bool visit[210]; // dfs 할 때 방문 여부 저장해둠
int match[210]; // 누구랑 매칭되어있는지 저장해둠 (매칭 안 되어있으면 0)


bool dfs(int a) {
	visit[a] = true; // 방문했다고 체크해두기

	int siz = map[a].size();
	for (int i = 0; i < siz; i++) { // map[a]에 들어있는 거 하나씩 확인
		int b = map[a][i];
		
		/*	1) b가 아직 매칭이 안 되어있는 경우
			2) b가 매칭이 되어있는데
			 그 매칭된 애 (== match[b]) 가 아직 방문을 안 했고
			 그거를 dfs돌렸을 때 다른 애랑 매칭이 되는 경우*/
		if (!match[b] || (!visit[match[b]] && dfs(match[b]))) {
			match[b] = a; // a랑 매칭하기
			return true; // 매칭 성공하면 true 리턴
		}
	}

	// 하나도 매칭되는 게 없으면 false 리턴
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int s;
		scanf("%d", &s);
		for (int j = 0; j < s; j++) {
			int a;
			scanf("%d", &a);
			map[i].push_back(a);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) cnt++; // cnt : 매칭 성공 개수
	}

	printf("%d", cnt);

}