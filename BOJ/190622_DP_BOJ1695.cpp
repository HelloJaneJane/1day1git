// ALOHA 여름 멘토링 중급반 : DP
// 백준 1695번 - 팰린드롬 만들기

/*
<구간dp>

[  [  ]  [  ]  ] << 이런 식으로 안쪽 구간의 값들로 바깥쪽 구간의 값 구하기

팰린드롬
1. 수 배열을 입력을 받고
2. 양 끝을 비교한다
 >> 같으면 : 구간을 좁힐 수 있다
  f(s,e) ... arr[s]==arr[e] -> f(s+1,e-1)
 >> 다르면 : 하나를 추가해준다 (추가해줬으니까 +1)
  f(s+1,e)+1 이나 f(s,e-1)+1 중 작은 값 선택
3. 종료조건 : 점점 좁혀주다가 만날 때


    0 1 2 3 4
  [ 1 2 3 4 2 ]
    s       e
-> 1이랑 2랑 다르니까 추가해야된다
 근데 추가하는 방법이 두 가지 : 왼쪽에추가 or 오른쪽에추가

    0 1 2 3 4
  [ 1 2 3 4 2 1 ]
     s+1    e

    0 1 2 3 4
[ 2 1 2 3 4 2 ]
    s    e-1

*/


#include <stdio.h>
#include <algorithm>
using namespace std;

int n;

int num[5010];

int dp[5010][5010];

int palin(int s, int e) {
	if (dp[s][e]) return dp[s][e];

	if (s >= e) return 0; // 범위 벗어나면 ㅃㅃ

	// 같은 숫자면 확인하는 구간 좁힌다 (양 끝 하나씩 줄임)
	if (num[s] == num[e])
		return dp[s][e] = palin(s + 1, e - 1);

	// 다른 숫자면 왼쪽이나 오른쪽에 추가한다
	// 둘 중 어떤 게 정답이냐면 최종 리턴 값이 작은 거 (최솟값 찾는 문제니까)
	else
		return dp[s][e] = min(palin(s + 1, e) + 1, palin(s, e - 1) + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &num[i]);

	printf("%d", palin(0, n - 1));

	return 0;
}