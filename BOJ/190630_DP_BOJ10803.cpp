// ALOHA 여름 멘토링 중급반 : DP
// 백준 10803번 - 정사각형 만들기


/*
무조건 둘로 나눠져야하니까
n*m 짜리 -> n-k*m 짜리 + k*m 짜리 (k=1 ~ n-1/2)
	아니면  n*m-k 짜리 + n*k 짜리 (k=1 ~ m-1/2)
로 쪼갠다. 그 안에서 최솟값 dp에 저장해두고 꺼내오면되는데

아니 이렇게까지했더니 시간초과... 근데 도저히 못줄이겠어서 구글링했더니
i랑 j랑 차이가 클 때 최적화시키는 법이 있더라
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int n, m;

int dp[10010][110];

int get_dp(int i, int j) {
	if (dp[i][j] != INF) return dp[i][j];

	if (i == j) return dp[i][j] = 1;

	/////////////////////////////// 증명.. 밍....
	/*
	i가 j에 비해 많이 큰 경우에는, 한 변의 길이가 j인 정사각형을 이용해 분할하는 것이 효율적임을 알 수 있다.
	따라서, 적절히 상수를 조절하면서 실험해보면, 다음의 점화식을 얻게 된다.
	--> https://blog.leejseo.com/73
	*/
	if (3 * i >= j * j) return dp[i][j] = get_dp(i - j, j) + 1;

	int save = INF;
	for (int k = 1; k <= j / 2; k++) {
		save = min(save, get_dp(i, k) + get_dp(i, j - k));
	}
	for (int k = 1; k <= i / 2; k++) {
		save = min(save, get_dp(k, j) + get_dp(i - k, j));
	}
	return dp[i][j] = min(dp[i][j], save);
}

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = INF;
		}
	}

	printf("%d", get_dp(n, m));
}