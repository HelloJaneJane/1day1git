// 백준 10026번 : 적록색맹

/*
map : RGB 중 하나
적록색맹이 없으면 같은 글자끼리만 연결됨
적록색맹이 있으면 같은 글자끼리 + R이랑 G는 붙어있으면 연결됨

BFS를 돌린다
1. n^2개의 칸을 다 탐색
2. 방문하지 않은 칸이면 큐에 넣는다
3. 큐에 들어있는 칸에 인접한 칸들을 확인
 -> 1) 적록색맹 없을 때 : 아직 방문 X && 같은 글자면
	2) 적록색맹 있을 때 : 아직 방문 X && 같은 글자 || 하나만 B이지 않으면
 방문 체크 + 큐에 넣기

 -> 그럼 큐가 빌 때까지 반복하면 시작한 거랑 같은 영역인 건 다 확인하게 됨
 '큐 반복'<< 을 시행한 횟수가 총 영역의 수
*/


#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int n;

char map[105][105];

// 초기화하기 귀찮아서 1번 경우 / 2번 경우 나눠서 선언해버림
bool visit1[105][105];
queue<pair<char, pair<int, int> > > qu1;
bool visit2[105][105];
queue<pair<char, pair<int, int> > > qu2;

// 네 방향 탐색하는 용
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

// 적록색맹일 때 두 글자가 언제 같아보이는지 알려주는 함수
bool same2(char c1, char c2) {
	// 하나만 B이면 다르게 보인다 (나머지는 다 같음)
	if ((c1 == 'B' && c2 != 'B') || (c1 != 'B' && c2 == 'B')) return false;
	return true;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	// 적록색약이 아닌 사람 : 1번 경우
	int ans1 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			// 방문 안 한 거 -> 그 영역의 시작
			if (!visit1[i][j]) {
				qu1.push({ map[i][j],{i,j} });
				visit1[i][j] = true;
				ans1++; // 영역의 수
			}

			// 큐 반복
			while (!qu1.empty()) {
				char nowChar = qu1.front().first;
				int nowY = qu1.front().second.first;
				int nowX = qu1.front().second.second;
				qu1.pop();

				for (int i = 0; i < 4; i++) {
					int toY = nowY + dy[i];
					int toX = nowX + dx[i];
					char toChar = map[toY][toX];

					// 범위 벗어나면 ㅃㅃ
					if (toY < 0 || n <= toY || toX < 0 || n <= toX) continue;

					// 방문 안 했고 && 글자가 같으면
					if (!visit1[toY][toX] && toChar == nowChar) {
						qu1.push({ toChar,{toY,toX} });
						visit1[toY][toX] = true;
					}
				}
			}
		}
	}

	// 적록색약이 맞는 사람 : 2번 경우
	int ans2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (!visit2[i][j]) {
				qu2.push({ map[i][j],{i,j} });
				visit2[i][j] = true;
				ans2++;
			}

			while (!qu2.empty()) {
				char nowChar = qu2.front().first;
				int nowY = qu2.front().second.first;
				int nowX = qu2.front().second.second;
				qu2.pop();

				for (int i = 0; i < 4; i++) {
					int toY = nowY + dy[i];
					int toX = nowX + dx[i];
					char toChar = map[toY][toX];

					if (toY < 0 || n <= toY || toX < 0 || n <= toX) continue;

					// 적록색맹 있으니까 글자가 그냥 같으면 ㄴㄴ (1번 경우랑 여기만 다름)
					if (!visit2[toY][toX] && same2(toChar, nowChar)) {
						qu2.push({ toChar,{toY,toX} });
						visit2[toY][toX] = true;
					}
				}
			}
		}
	}


	printf("%d %d", ans1, ans2);
}