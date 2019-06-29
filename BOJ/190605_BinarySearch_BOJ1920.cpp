// 백준 1920번 : 수 찾기

/*
10만 개 짜리 배열을 10만 번 탐색하려면
linear search 이용하면 시간 초과니까 binary search를 쓴다!

0. 일단 정렬한다
1. left~right 를 탐색. mid = 정가운데
2. 내가 보고있는 숫자가 mid보다 작다 -> left~mid 탐색
	크다 -> mid~right 탐색

*/


#include <stdio.h>
#include <algorithm>
using namespace std;

int A[100000];

int BS(int left, int right, int num) {

	int mid = (left + right) / 2;

	if (left <= right) {
		// left가 right 보다 커지면 그 수는 존재 안 한다는 뜻

		if (num < A[mid]) // mid에 있는 수 보다 작으면
			return BS(left, mid - 1, num); // 왼쪽 절반 탐색

		else if (num > A[mid])	// mid에 있는 수 보다 크면
			return BS(mid + 1, right, num); // 오른쪽 절반 탐색

		else return 1; // mid에 있는 수가 그 수! 찾았다!
	}

	return 0; // 못 찾았다
}

int main() {
	int N, M, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	scanf("%d", &M);

	// 일단 정렬
	sort(A, A + N);
	
	while (M--) {
		scanf("%d", &num);
		printf("%d\n", BS(0, N - 1, num));
	}
	return 0;
}