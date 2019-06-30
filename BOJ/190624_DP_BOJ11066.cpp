// ALOHA 여름 멘토링 중급반 : DP
// 백준 11066번 - 파일 합치기

/*
memset(dp,INF,sizeof(dp)) 때문에 한 시간이나 고민한 문제 ㅎㅎ..
2차원 배열 초기화할 때는 0 아니면 안 쓰는 게 나은 거 같다

다른 분 풀이 보니까 memset(dp,0x3f,sizeof(dp)) 하고
if(dp[i][j]!=0x3f3f3f3f) 로 하더라.. 왤까
*/

/*
4 3 3 5 를 합치는 방법은 4/335, 43/35, 433/5 로 쪼개서 합치는 거 중 최소값
쪼개진 구간을 또 쪼개고 쪼개고... 구간dp!!

[4335]=min([4]+[335],[43]+[35],[433]+[5])

[335]=min([3]+[35],[33]+[5])
[433]=min([4]+[33],[43]+[3])

[한자리] 는 자기 자신을 합치는 거니까 0
[두자리] 는 인접하는 거니까 두 수 합

여기에 각각 꺼 다 합한 거 더해줘야함
*/

#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 987654321

int file[510];
int sum[510];		// sum[i] : 1번째~i번째 누적 합
int dp[510][510];	// dp[i][j] : i번째~j번째 합 최소


int get_dp(int i, int j) {
// i번째~j번째 파일을 합치는 비용의 최솟값을 가져온다

	if (dp[i][j] != INF) return dp[i][j];

	// i==j면 자기 자신을 합치는 거니까 비용은 0
	if (i == j) return dp[i][j] = 0;

	// j==i+1이면 자기랑 인접한 거랑 합치는 거니까 비용은 두 파일 크기 합
	if (j == i + 1) return dp[i][j] = file[i] + file[j];

	// 아닐 경우에는 구간dp!! i~j 를 i~k / k+1~j 로 쪼개서 합친다
	for (int k = i; k < j; k++) {
	// 쪼개는 여러 경우 중에 최솟값이 dp[i][j]가 된다
		dp[i][j] = min(dp[i][j], get_dp(i, k) + get_dp(k + 1, j));
	}
	// 쪼개져있는 부분이랑 부분을 합치려면 i부터 j까지 파일 크기 다 추가해야함
	return dp[i][j] = dp[i][j] + sum[j] - sum[i - 1];
}


int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d", &k);

		for (int i = 1; i <= k; i++) {
			scanf("%d", &file[i]);
			sum[i] = sum[i - 1] + file[i];

			// 최솟값으로 갱신할 거니까 INF로 초기화
			for (int j = 1; j <= k; j++) dp[i][j] = INF;
		}

		// 1장부터 k장까지 합치는 최소 비용 구할 거야
		printf("%d\n", get_dp(1, k));
	}
}