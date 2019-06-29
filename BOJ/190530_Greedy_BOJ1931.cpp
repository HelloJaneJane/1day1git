// 백준 1931번 : 회의실배정

/*
0. 일단 끝나는 시간 순서로 정렬해 놓고 시작한다
1. 제일 빨리 끝나는 거 선택 
2. 선택한 거랑 안 겹치는 거 중에 제일 빨리 끝나는 거 선택
(끝나는 시간 순서로 정렬해놨으니까 제일 먼저 탐색되는 안 겹치는 거가 제일 빨리 끝남)
3. 반복

이러면 최대한 많은 회의실 고를 수 있다!
앞에서부터 만족하는 거 선택하는 그리디 알고리즘
*/



#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

int n;

pair<int, int> arr[100010]; // {끝나는시간, 시작하는시간}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int s, f;
		scanf("%d%d", &s, &f); // start, finish
		arr[i] = { f,s };	// 끝나는 순으로 정렬할 거니까 f를 first로
	}

	sort(arr, arr + n);		// 0. 먼저 끝나는 순서대로 정렬


	// 일단 맨 처음 꺼 선택하고 시작
	int cnt = 1;			// 선택 개수 cnt
	int now = arr[0].first;	// 지금 선택한 거 끝나는 시간 now


	// 차례로 탐색
	for (int i = 1; i < n; i++) {

		// 탐색하고 있는 게 선택된 거랑 안 겹칠 때
		// (arr[i]의 시작 시간이 now 보다 늦을 때)
		if (arr[i].second >= now) { 
			// arr[i]를 선택한다
			cnt++;			// 선택 개수 +1
			now = arr[i].first; // now 갱신
		}
	}

	// 총 선택 개수가 최종 배정된 회의실 개수
	printf("%d", cnt);

	return 0;
}