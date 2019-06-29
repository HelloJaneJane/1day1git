// ALOHA 고급반 6주차 - 볼록껍질 강의 / 백준 1708번

/*
Convex Hull 문제 푸는 법은
1) 좌표 순으로 정렬해서 제일 작은 거부터 봄 : Monotone Chain
2) x좌표 제일 작은 점에 대한 기울기 순으로 정렬 : Graham Scan

나는 스택 이용하는 모노톤 체인 방법으로 풀었음
1. 스택에서 위에 두 점이랑 내가 지금 보고 있는 점을 CCW한다
2. 만족하면 현재 점을 넣고, 안 만족하면 위에 꺼 하나 빼고 다시 CCW한다
(만족할 때까지 계속 pop 반복)
3. 점들을 끝까지 다 봤으면 스택 안에 남아있는 것들 다 이은 게 껍질이라는 뜻
그래서 아래 껍질, 위 껍질 이으면 볼록 껍질 완성!
*/



#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


// x, y 좌표를 pair로 쓸 거니까 안 헷갈리게 매크로 설정해둠
#define x first
#define y second


// Counter Clock Wise
// A, B, C 세 점 이은 게 반시계 방향이면 +, 아니면 - 값 리턴 (0이면 평행)
long long ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
	return 1LL * (B.x - A.x)*(C.y - A.y) - 1LL * (B.y - A.y)*(C.x - A.x);
}
// 1LL 곱하면 롱롱 값으로 변환 됨


int n;

pair<int, int> arr[100010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].x, &arr[i].y);
	sort(arr, arr + n); // 좌표 순으로 정렬한다

	// low는 x좌표 작은거->큰거, up은 큰거->작은거 순서로 확인하기

	// 아래(Lower) 껍질
	stack< pair<int, int> > L;
	L.push(arr[0]);
	L.push(arr[1]);
	for (int i = 2; i != n; i++) {
		pair<int, int> now = arr[i]; // 지금 내가 보는 점
		pair<int, int> top, top2; // 스택 안에 있는 위에 두 점 (top은 맨 위, top2는 두 번째 맨 위)
		do {
			top = L.top();
			L.pop();
			if (L.empty()) { break; }
			top2 = L.top();
		} while (ccw(top2, top, now) <= 0); // 세 점이 CCW 만족할 때 까지 반복
		L.push(top);
		L.push(now);
	}

	// 위(Upper) 껍질
	stack< pair<int, int> > U;
	U.push(arr[n - 1]);
	U.push(arr[n - 2]);
	for (int i = n - 1; i >= 0; i--) {
		pair<int, int> now = arr[i];
		pair<int, int> top, top2;
		do {
			top = U.top();
			U.pop();
			if (U.empty()) { break; }
			top2 = U.top();
		} while (ccw(top2, top, now) <= 0);
		U.push(top);
		U.push(now);
	}

	int cnt = 0;
	while (!L.empty()) { // 아래 껍질에 속하는 점 개수 세기
		cnt++;
		L.pop();
	}
	while (!U.empty()) { // 위 껍질에 속하는 점 개수 세기
		cnt++;
		U.pop();
	}

	printf("%d", cnt - 2); // 양 끝 겹치는 점 두 개는 한 번씩 빼주기
}