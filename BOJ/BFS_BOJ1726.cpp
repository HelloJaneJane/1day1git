// ALOHA ���� ���丵 �߱޹� : �׷��� - Ž�� (BFS, DFS)
// ���� 1726�� - �κ�

/*
bfs ������ Ž���Ѵ�.
�ٵ� �׳� �������� ���� �� �ƴϴϱ� x+dx[], y+dy[] �ϴ� �κ��� �ٲ����
��� 1. go k -> x,y�� +1, -1 �ϴ��� +1*k, -1*k �ؾ���
��� 2. turn dir -> x,y�� �״�� �ΰ� ���� �ٲٱ�

go k �� �� ������ ����
���� ������ ���� 0�̸� �� �� �ִ�!��� �Ǵ��ϸ� �� �ǰ�
�� ���� �����ϱ� ���� 1�� ������ �߰��� ���� ���θ����ִٴ� �Ŵϱ� �н��ؾ���
*/


#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

#define INF 987654321

int m, n;

int map[105][105];

// �� '��ġ'�� �� '����'���� �湮�ߴ���
// INF�� ���� �� �湮 �� �Ű�, ���������� �󸶳� �ɷȴ��� �ּ� cnt�� ����
int visit[105][105][5];

typedef struct P {
	int x; // �� (1~n)
	int y; // �� (1~m)
	int d; // ���� (��1 ��2 ��3 ��4)
} P;

P st; // ������
P en; // ������

// ��1 ��2 ��3 ��4 (0�� �о�)
int dx[5] = { 0,1,-1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

queue<pair<int, P> > qu;

// �� ����ü�� ���� ������ �Ǵ�
bool equal(P P1, P P2) {
	if (P1.x == P2.x && P1.y == P2.y && P1.d == P2.d) return true;
	else return false;
}

// �� �� �ִ� ��ǥ���� �Ǵ�
bool isok(P p) {
	if (1 <= p.x && p.x <= n && 1 <= p.y && p.y <= m && !map[p.y][p.x]) return true;
	else return false;
}


int main() {
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);

			for (int k = 1; k <= 4; k++) visit[i][j][k] = INF;
		}
	}

	scanf("%d%d%d%d%d%d", &st.y, &st.x, &st.d, &en.y, &en.x, &en.d);

	int ans = INF;
	qu.push({ 0,st });
	visit[st.y][st.x][st.d] = 0;

	// BFS ����
	while (!qu.empty()) {
		P nowP = qu.front().second;
		int nowCnt = qu.front().first;
		qu.pop();

		// ������ en�̶� �������� ans �� ����
		if (equal(nowP, en)) ans = min(ans, nowCnt);


		int toX, toY, toD;
		int toCnt = nowCnt + 1;
		P toP;

		// ��� 1 : go k
		for (int k = 1; k <= 3; k++) {
			toD = nowP.d;
			toX = nowP.x + k * dx[toD];
			toY = nowP.y + k * dy[toD];

			toP = { toX,toY,toD };

			// �߰��� �� ���̶� �� ������ �� �̻� go k ���� �Ұ�
			if (!isok(toP)) break;

			// toP ���� �� �� �ִ� ���̰� �� ���� cnt ���̸� ����
			if (isok(toP) && visit[toY][toX][toD] > toCnt) {
				qu.push({ toCnt,toP });
				visit[toY][toX][toD] = toCnt;
			}
		}


		// ��� 2 : turn dir
		// ��,��->��,�� : 1,2->3,4  or  ��,��->��,�� : 3,4->1,2
		toX = nowP.x;
		toY = nowP.y;

		// ��,��->��  or  ��,��->��
		if (nowP.d == 1 || nowP.d == 2) toD = 3;
		else toD = 1;

		toP = { toX,toY,toD };
		if (isok(toP) && visit[toY][toX][toD] > toCnt) {
			qu.push({ toCnt,toP });
			visit[toY][toX][toD] = toCnt;
		}

		// ��,��->��  or  ��,��->��
		if (nowP.d == 1 || nowP.d == 2) toD = 4;
		else toD = 2;

		toP = { toX,toY,toD };
		if (isok(toP) && visit[toY][toX][toD] > toCnt) {
			qu.push({ toCnt,toP });
			visit[toY][toX][toD] = toCnt;
		}
	}

	printf("%d", ans);
}

