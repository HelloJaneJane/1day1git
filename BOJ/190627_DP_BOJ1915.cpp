// ALOHA 여름 멘토링 중급반 : DP
// 백준 1915번 - 가장 큰 정사각형


/*
(0,0)~(i,j) 에서 가장 큰 정사각형 한 변의 길이를 찾자
이때 (i,j)가 1일 때만 찾아서 dp에 넣을 거야
map이 0이면 dp도 0이야!

(0,0)~(i-1,j-1) / (0,0)~(i-1,j) / (0,0)~(i,j-1) 에서 가장 큰 정사각형 한 변의 길이
중에 젤 작은 거에 +1 한 값!

(만약에 dp[i-1][j-1], dp[i-1][j], dp[i][j-1] 중에 하나라도 0이면 dp[i][j]는 1)

map[i][j]가 1이어서 정사각형의 한 변 길이가 늘어나려면
최소한 내 왼쪽, 위쪽, 대각선왼쪽위쪽 << 셋 다 1이여야하니까


그러고 최종적으로는 내가 dp에 채웠던 값 중에 제일 큰 수가
이 map 전체에서 제일 큰 정사각형 한 변 길이가 되고
그걸 제곱하면 면적이 된다!
*/


/*
예시

map
0100
0111
1110
0010

dp
0100
0111
1120
0010


map
0111
0111
0111
1101

dp
0111
0122
0123
1101

*/


#include <stdio.h>
#include <algorithm>
using namespace std;

int map[1010][1010];

int dp[1010][1010]; // dp[i][j] : (0,0)~(i,j)에서 가장큰정사각형 한변길이
// map이 1일때만dp가 채워진다!!!!

int n, m, ans;

int main() {
	scanf("%d%d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (map[i][j]) {
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
				ans = max(ans, dp[i][j]);
			}
		}
	}

	/*for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			printf("%d", dp[i][j]);
		}
		printf("\n");
	}*/

	printf("%d", ans*ans);
	return 0;

}