// 백준 2448번 : 별찍기 11 (재귀 별찍기)

/*
아무리 봐도 재귀함수를 이용해야할 것 같은데
(그리고 옛날에 재귀 처음 배울 때 이 문제 풀어보라 했었는데 못 풀었었음)
프린트는 한 줄 씩 해야하고....
도저히 모르겠어서 힌트를 찾아봤더니 시작 좌표를 넘겨줘서 하는 팁을 발견!
거기다 k가 10이하라서 2차원 배열로 다 잡아버려도 메모리 넉넉하더라
*/

#include <stdio.h>

int n;

bool map[3100][6200];
// 3*(2^10)=3*1024=3072

void star(int h, int x, int y) {

	if (h == 3) {
	/*	높이 3짜리 기본형일 때 별 찍기
		  *
		 * *
		*****
	*/
		map[y][x] = 1;
		map[y + 1][x - 1] = map[y + 1][x + 1] = 1;
		map[y + 2][x - 2] = map[y + 2][x - 1] = map[y + 2][x] = map[y + 2][x + 1] = map[y + 2][x + 2] = 1;
		return;
	}

	// 이전 단계로 재귀 넘어갈 때는 높이 절반으로 줄임 && 절반짜리 삼각형 세 개 생김
	star(h / 2, x, y);					// 가운데 위에 꺼 하나
	star(h / 2, x - h / 2, y + h / 2);	// 왼쪽 밑에 꺼 하나
	star(h / 2, x + h / 2, y + h / 2);	// 오른쪽 밑에 꺼 하나
}

int main() {
	scanf("%d", &n);
	
	// 시작은 높이 n짜리, 출발점 x좌표는 n, y좌표는 1
	star(n, n, 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			if (map[i][j]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}

}