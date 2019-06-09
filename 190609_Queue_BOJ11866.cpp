// 백준 11866번 : 조세퍼스 문제 0

/*
n명이 원으로 앉아있다 -> queue 이용해서 pop-push 반복
*/


#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, k;
queue<int> q;
vector<int> v;

int main() {
	scanf("%d%d", &n, &k);

	// 일단 1~n을 큐에 넣는다
	for (int i = 1; i <= n; i++) q.push(i);

	// 모두가 선택될 때까지 (== 큐가 빌 때까지) 반복
	while (!q.empty()) {
		// 1회 반복 시 k개 탐색

		// 처음부터 k-1개는 앞에 껄 빼서 뒤로 넣는다 (push후 pop)
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		// k번 째꺼는 그냥 뺀다
		v.push_back(q.front()); // 나중에 출력할 벡터에 넣음
		q.pop();
	}

	// 출력을 할 건데
	for (int i = 0; i < n; i++) {
		if (i == 0) printf("<"); // 맨 처음
		printf("%d", v[i]);			
		if (i == n - 1) printf(">"); // 맨 마지막
		else printf(", ");
	}
}