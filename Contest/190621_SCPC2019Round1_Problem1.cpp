// 2019 SCPC 1차예선 - 1번 : 오르락 내리락

/*
짝수 : 2로 나눈다 / 홀수 : 1을 더한다
1로 만들려면 몇 번의 작업을 해야할까?

3->4->2->1	: dp[3] = 3 = 1+dp[4]
4->2->1		: dp[4] = 2 = 1+dp[2]

i가 홀수 : dp[i]=1+dp[i+1]
i가 짝수 : dp[i]=1+dp[i/2]

재귀함수로 dp배열을 채운다
*/

/*
시간초과 때문에 다섯 번이나 틀렸다
별 짓 거리를 다 해보다가
결국 세그먼트 트리로 풀었다
*/

#include <iostream>
#include <stdio.h>
using namespace std;

#define ll long long
#define mid (s+e)/2
#define Lchild node*2
#define Rchild node*2+1

ll Answer;
int n1, n2;

int dp[1000010] = { 0,0,1 };
ll tree[4000040];

int fill(int i) {
	if (i == 1) return 0; // 이거 예외 안 해놓으면 1->2로 가버린다
	if (dp[i]) return dp[i];

	if (i % 2 == 0) { // 짝수
		return dp[i] = 1 + fill(i / 2);
	}
	else { // 홀수
		return dp[i] = 1 + fill(i + 1);
	}
}

ll init(int node, int s, int e) {
	if (s == e) // leaf노드 일 때
		return tree[node] = dp[s];
	else
		return tree[node] = init(Lchild, s, mid) + init(Rchild, mid + 1, e);
}

// s~e : 지금 보고있는 구간,  l~r : 구해야하는 구간
ll sum(int node, int s, int e, int l, int r) {
	if (e < l || r < s) // s~e가 전혀 포함 안 될 때
		return 0;
	if (l <= s && e <= r) // s~e가 완전 포함일 때
		return tree[node];
	return sum(Lchild, s, mid, l, r) + sum(Rchild, mid + 1, e, l, r);
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, test_case;

	cin >> T;

	// dp배열을 미리 채워놓는다
	// 거꾸로 하는 게 함수 호출 횟수가 적다
	for (int i = 1000000; i >= 3; i--) {
		dp[i] = fill(i);
	}

	init(1, 1, 1000000);

	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		cin >> n1 >> n2;

		Answer = sum(1, 1, 1000000, n1, n2);

		cout << "Case #" << test_case + 1 << '\n';
		cout << Answer << '\n';
	}

	return 0;
}