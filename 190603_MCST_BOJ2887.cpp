// ALOHA �˰���� 8���� ���� �غ�
// MCST - Kruskal �˰���


/*
�����Ͱ� �ʹ� ���Ƽ� ������ �� ���� ���� ����
min(x��ǥ����, y��ǥ����, z��ǥ����)�� ����ġ�̹Ƿ�
x��/y��/z�� << �� �� �����ؼ� �ٷ� ���� �ִ� �Ÿ� �������� �����Ѵ�



*/

#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int n;

int p[100010];


// ���� �����Ϸ��� ���� �迭 �� ��
pair<int, int> mapX[100010];
pair<int, int> mapY[100010];
pair<int, int> mapZ[100010];

// {-����ġ,{������,����}}
priority_queue<pair<int, pair<int, int> > > pq;

// �� �迭���� ������ ���� pq�� ���� (�� ��)
void pq_push(pair<int, int> map[]) {
	for (int i = 1; i <= n - 1; i++) {
		int u = map[i].second;
		int v = map[i + 1].second;
		int w = map[i].first - map[i + 1].first;
		if (w < 0) w *= -1;
		pq.push({ -w,{u,v} });
	}
}

// ��� �����ϴ� ��� find
int find(int x) {
	if (p[x] == x) return x;
	else return p[x] = find(p[x]);
}


int main() {
	scanf("%d", &n);

	// n�� �༺ -> x,y,z ���� ����
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		mapX[i] = { x,i };
		mapY[i] = { y,i };
		mapZ[i] = { z,i };
	}
	// ���� ����
	sort(mapX + 1, mapX + n + 1);
	sort(mapY + 1, mapY + n + 1);
	sort(mapZ + 1, mapZ + n + 1);
	
	// ���� push
	pq_push(mapX);
	pq_push(mapY);
	pq_push(mapZ);

	// �ϴ� ���� parent == �� �� �ʱ�ȭ
	for (int i = 1; i <= n; i++) p[i] = i;

	int ans = 0;

	// ����ġ ���� ���� �ͺ��� Ž��
	while (!pq.empty()) {
		int w = -pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;

		a = find(a); // a�� root
		b = find(b); // b�� root

		if (a != b) { // �ٸ� �����̸� union
			ans += w; // MCST�� ���õ�
			p[a] = b;
		}
		pq.pop();
	}

	printf("%d", ans);

}