// 백준 10868번 : 최솟값

/*
a번~b번 에 있는 수들 중 최솟값을 찾아야 한다
세그먼트트리를 이용한다!

leaf노드들 == arr

arr[i] == i번~i번에 있는 수 중 최솟값 이라고 생각
(start가 i, end가 i) (s==e인 경우)
*/


#include <stdio.h>
#include <algorithm>
using namespace std;

// 매크로 설정해두는 게 코드가 이뻐진다
#define mid (s+e)/2
#define Lchild node*2
#define Rchild node*2+1

#define INF 987654321

int n, m;
int arr[100010];
int tree[400040]; // 트리 크기는 arr의 4배가 적당하다

// 트리 만들기
int init(int node, int s, int e) {
	// leaf노드 일 땐 arr값을 넣고 끝내기
	if (s == e)
		return tree[node] = arr[s];
	
	// s~e의 최솟값은 s~mid, mid+1~e 둘 중 작은 값
	else
		return tree[node] = min(init(Lchild, s, mid), init(Rchild, mid + 1, e));
}

int a, b;

// 내가 원하는 범위에 해당하는 답 찾기
int ans(int node, int s, int e) {
	// a~b는 내가 원하는 범위, s~e는 이 함수가 지금 보고있는 범위

	// 범위에서 벗어나면 ㅃㅃ
	if (e < a || b < s) return INF;
	
	// 범위에 전부 속하면 tree에 담겨있는 값 갖고오기
	if (a <= s && e <= b) return tree[node];

	// 범위에 일부 속하면 절반 쪼개서 다시 확인
	return min(ans(Lchild, s, mid), ans(Rchild, mid + 1, e));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	// 트리를 맨 처음 만들 땐 1번~n번의 최솟값을 뜻하는 root (노드번호 1) 부터 시작
	init(1, 1, n);
	

	while (m--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", ans(1, 1, n));
	}

	return 0;
}
