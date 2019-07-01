// ALOHA 여름 멘토링 중급반 : DP
// 백준 1509번 - 팰린드롬 분할

#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 987654321

char str[2505];

int dp[2505];
// dp[i] : 0~i 안에 팰린드롬 최소 개수

int ispalin[2505][2505];
// ispalin[i][j] : i~j 가 팰린드롬인지?
// 초기화 : -1 / 팰린드롬이면 1, 아니면 0

bool ispal(int s, int e) {
	if (s > e) return 1;

	if (ispalin[s][e] != -1) return ispalin[s][e];

	if (str[s] != str[e]) return ispalin[s][e] = 0;
	else return ispalin[s][e] = ispal(s + 1, e - 1);
}

int main() {
	scanf("%s", str + 1); // 1베이스로 하려고
	int l = strlen(str + 1);

	memset(ispalin, -1, sizeof(ispalin));

	for (int i = 1; i <= l; i++) {
		ispalin[i][i] = 1;
		dp[i] = INF;

		for (int j = 1; j <= i; j++) {
			// j~i 가 팰린드롬이면
			// [0~i 중에 개수]는 [0~j-1 중에 개수]+1
			if (ispal(j, i)) {
				dp[i] = min(dp[i], dp[j - 1] + 1);
			}
		}
	}

	printf("%d", dp[l]);
}