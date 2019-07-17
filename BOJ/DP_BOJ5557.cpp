// ALOHA 여름 멘토링 중급반 : DP
// 백준 5557번 - 1학년

/*
dp[i][j] : i번째 수까지 사용해서 j를 만들 경우의 수

arr[0]~arr[i-1] 을 이용해서 j를 만들어냈다
그러면 arr[0]~arr[i]를 이용해서는 j+arr[i] 이나 j-arr[i]를 만들어낼 수 있다
그래서 dp[i][j+arr[i]], dp[i][j-arr[i]] 에는 dp[i-1][j] 가 들어간다
*/


#include <stdio.h>

int n;
int ans; // 마지막에 답으로 나와야하는 수
int arr[110]; // 0 ~ n-2 칸에 등식 이루는 수 담겨있음

long long dp[110][21];
// dp[i][j] : i번째 수까지 사용해서 j를 만들 경우의 수 
// dp[n-2][ans] 가 정답!

bool isOK(int t) { return (t >= 0 && t <= 20) ? true : false; }

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) scanf("%d", &arr[i]);
	scanf("%d", &ans);

	dp[0][arr[0]] = 1;

	for (int i = 1; i <= n - 2; i++) {
		for (int j = 0; j <= 20; j++) {
			// dp[i-1][j]가 0이면 (i-1번째 수까지로 j를 만들 수 없으면) 패쓰
			if (dp[i - 1][j]) {
				if (isOK(j + arr[i])) dp[i][j + arr[i]] += dp[i - 1][j];
				if (isOK(j - arr[i])) dp[i][j - arr[i]] += dp[i - 1][j];
			}
		}
	}
	printf("%lld", dp[n - 2][ans]);
	return 0;
}