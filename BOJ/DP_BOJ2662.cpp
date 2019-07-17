// ALOHA 여름 멘토링 중급반 : DP
// 백준 2662번 - 기업투자


#include <stdio.h>

int arr[310][21];
// arr[i][0] = i : 투자금액
// arr[i][j]	 : i원을 j번 기업에 투자했을 때 이익

int dp[310][21];
// dp[i][j] : i원까지를 j번 기업에 투자했을 때 최대 이익

int ans[310][21];
// ans[i][j] : i원까지를 투자해서 최대 이익 얻을 때 j번 기업에 투자되는 돈

int main() {
	int n, c; // n : 총 투자금액 , c : 기업 개수
	scanf("%d%d", &n, &c);

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	// 일단 맨 처음에 i원을 1번 기업에 투자하면
	for (int i = 1; i <= n; i++) {
		// 최대 이익은 1번 기업이 주는 이익 그대로
		dp[i][1] = arr[i][1];
		// 이때 1번한테는 i원이 들어감
		ans[i][1] = i;
	}

	// 이제 기업(j)를 늘려가면서 돈을 분산 할 거야
	for (int j = 1; j <= c; j++) {
		for (int i = 1; i <= n; i++) {
			for (int k = 0; k <= i; k++) {
				// [i원을 j번에] 이익이랑 [i-k원을 j-1번에]+[k원을 j번에] 분산해서 이익이랑 비교
				if (dp[i][j] < dp[i - k][j - 1] + arr[k][j]) {
					// 분산한 게 더 크면 dp값 갱신
					dp[i][j] = dp[i - k][j - 1] + arr[k][j];
					// i원까지를 넣을 때 j번에는 k원이 들어감
					ans[i][j] = k;
				}
			}
		}
	}


	////////// 채우는 건 끝났고 이제 답 찾아내고 출력하기

	// 기업 번호 하나씩 늘려가면서 채웠으니까 c번(마지막)기업 칸 확인
	// 얼마까지 확인해서 넣었을 때가 최대인지 찾기
	int m = 0;
	int tmp = 0;
	for (int i = 0; i <= n; i++) {
		if (m < dp[i][c]) {
			m = dp[i][c]; // 최대이익
			tmp = i;	// 그때 i원까지 확인하고 넣음
		}
	}

	printf("%d\n", m); // 최대이익 출력

	// 각 기업에 얼마씩 들었는지 fin 배열에 넣어둠
	int fin[21];
	for (int i = c; i >= 1; i--) {
		// tmp : 남은 돈

		// i번 기업에 최종적으로 들어가는 돈은 ans[tmp][i]
		fin[i] = ans[tmp][i];
		
		if (i == c){ // for문 맨 처음 : c번 기업
			tmp = n - fin[i]; // 총 금액 n 중에 fin[c]만큼 c번에 넣었으니 남은 돈은 n-fin[c]
		}
		else {
			tmp = tmp - fin[i]; // tmp중에 fin[i]만큼 i번에 넣었으니 남은 돈은 tmp-fin[i]
		}
	}
	for (int i = 1; i <= c; i++) {
		printf("%d ", fin[i]);
	}

	return 0;
}