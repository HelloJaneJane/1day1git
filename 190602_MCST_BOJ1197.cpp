// ALOHA �˰���� 8���� ���� �غ�


/*
 MCST - Kruskal �˰���
*/

#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int root[10010];


// root ã�� �� ���� ��� ������
int find(int x) {
	if (x == root[x]) return x;
	return root[x] = find(root[x]); // ��� ����
}


// {-����ġ,{������,����}}
priority_queue <pair<int, pair<int, int>>> pq;
// ����ġ ������ ���� �� ���� �ֵ��� ����
// priority queue�� max heap�̴ϱ� ū ���� ���� �ö���Ƿ� -1 ���ϸ� min heap���ε� Ȱ�� ����



int main() {
	int V, E;
	scanf("%d%d", &V, &E);

	// �ϴ��� ���� parent == �� ��� �ʱ�ȭ
	for (int i = 1; i <= V; i++) {
		root[i] = i;
	}

	int ans = 0; // �ּ� ��� ��

	while (E--) { // ��� edge�� pq�� �־ ����
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		pq.push({ -c,{a,b} });
	}

	while (!pq.empty()) { // pq�� �ִ� ��� edge�� Ž��
		int w = -pq.top().first;		// ����ġ
		int a = pq.top().second.first;	// ������
		int b = pq.top().second.second;	// ����

		// root ã��
		a = find(a);
		b = find(b);

		if (a != b) { // �ٸ� �����̸�
			ans += w; // MCST�� edge�� �Ǵ�! ����ġ��ŭ ��� �߰�
			root[a] = b; // Union 
		}
		// ���� �����̸� �н��ϱ�

		pq.pop();
	}

	printf("%d", ans);
	return 0;
}