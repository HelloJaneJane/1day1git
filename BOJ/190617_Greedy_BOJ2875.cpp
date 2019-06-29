// 백준 2875번 : 대회 or 인턴

/*
여자 n명 + 남자 m명
-> 인턴 k명 + (여2남1) 최대 몇 팀?
*/

/*
일단 여자2명, 남자1명 뺀다
여자/남자 하나라도 모자라면 (남은 사람 수가 음수면) ㄴㄴ
남은 총 사람 수가 k명이 안 되면 ㄴㄴ
이거 통과되면 팀 수 ++
*/

#include <stdio.h>

int n, m, k;

int main() {
	scanf("%d%d%d", &n, &m, &k);

	int cnt = 0;
	while (1) {
		n -= 2;
		m -= 1;
		if (n < 0 || m < 0 || n + m < k) break;
		cnt++;
	}
	printf("%d", cnt);
}