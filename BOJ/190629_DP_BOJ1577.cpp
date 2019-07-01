// ALOHA 여름 멘토링 중급반 : DP
// 백준 1577번 - 도로의 개수


#include <stdio.h>
#include <algorithm>
using namespace std;

#define ll long long

ll dp[105][105];
// dp[i][j] : 0,0 ~ i,j 경우의 수

int map[105][105];
// a,b ~ a+1,b 공사하면 [c][d]가 1
// a,b ~ a,b+1 공사하면 [c][d]가 2
// 둘 다 하면 3, 안 하면 0

int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);

	// 공사 도로 map에 입력
	while (k--) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);

		if (d == b) {
			map[max(a, c) + 1][d + 1] |= 1;
		}
		else if (c == a) {
			map[c + 1][max(b, d) + 1] |= 2;
		}
	}

	dp[1][1] = 1;
	for (int i = 1; i <= m + 1; i++) {
		for (int j = 1; j <= n + 1; j++) {
			if (i == 1 && j == 1) continue;

			if (map[j][i] == 1) // 왼쪽 길 막힘. 아래서만 올 수 있음
				dp[j][i] = dp[j][i - 1];
			else if (map[j][i] == 2) // 아래 길 막힘. 왼쪽서만 올 수 있음
				dp[j][i] = dp[j - 1][i];
			else if (map[j][i] == 0) // 공사 안 하면
				dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
			else dp[j][i] = 0; // 둘 다 하면 여긴 못 가
		}
	}

	printf("%lld", dp[n + 1][m + 1]);
	return 0;
}