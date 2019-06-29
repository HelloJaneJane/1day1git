// ���� 9370�� : ��Ȯ�� ������

/*
�� �������� ���� �ִܰ�ο� �� ������ ���� �Ǵ���?
-> �ϴ� �ִܰ�δϱ� ���� ���ͽ�Ʈ�� �� �ž�

�� �� g-h ������ �� �ִܰ�ο� ������ �˱� ���ؼ�
map[g]���� {h,~} �� pq�� ������ �� Ȯ���ϸ� �ȴ�!
... ��� ���������� pq�� ��� �ٸ� ������ ���ŵ� ���� �ִ���

�׷��� ��θ� �ɰ��� ���ͽ�Ʈ�� �� �� ���ȴ� (�ð������� 3���� �����ε�)
�� ���� ���� �ִܰ���� dis����
�������� ���İ��� �ִܰ���� dis������ ���� ������
�������� ���ƴٴ� ���̹Ƿ� ����, �ٸ��� ����

*/


#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321

vector<pair<int, int> > map[2010]; // map[a]={b,d}

priority_queue<pair<int, int> > pq; // {-�Ÿ�,��}
int dis_s[2010]; // s���� �����ؼ� �� ������ ���� �ִ� ��� �Ÿ�
int dis_g[2010]; // g���� ����
int dis_h[2010]; // h���� ����

int n, m, t, s, g, h;

vector<int> fin; // �������� (������� �����س���)


// ���ͽ�Ʈ�� �� �� ���� �ǵ� ���� ���� �������ϱ� �Լ��� �������ȴ�
void djikstra(int k, int dis[]) {
	// ������ k, �� ������ ���� �ִ� ��� �Ÿ� �迭 dis

	dis[k] = 0;
	pq.push({ 0,k });

	// pq�� {-�Ÿ�, ��} �� �־ ���� ���� �Ÿ����� Ž��
	while (!pq.empty()) {
		int now = pq.top().second;		// ���� �����ִ� ��
		int nowdis = -pq.top().first;	// �������� ���Ŀ� �Ÿ�
		pq.pop();

		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i].first;		// ������ �� ��
			int nextdis = map[now][i].second;	// ����~���� ���� �Ÿ�
			
			// dis�� ���� ������ �����ϰ� pq�� �ֱ�
			if (dis[next] >= nowdis + nextdis) { 
				dis[next] = nowdis + nextdis;
				pq.push({ -dis[next],next });
			}
		}
	}
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d%d%d", &n, &m, &t, &s, &g, &h);

		// �ʱ�ȭ
		for (int i = 1; i <= n; i++) {
			map[i].clear();
			dis_s[i] = dis_g[i] = dis_h[i] = INF;
		}

		// ���� �Է�
		for (int i = 0; i < m; i++) {
			int a, b, d;
			scanf("%d%d%d", &a, &b, &d);
			map[a].push_back({ b,d });
			map[b].push_back({ a,d });
		}

		// ������ �Է�
		fin.clear();
		for (int i = 0; i < t; i++) {
			int x;
			scanf("%d", &x);
			fin.push_back(x);
		}
		// ���� �ź��� ����� �Ŵϱ� �����س���
		sort(fin.begin(), fin.end());

		// ������ s, ����1 g, ����2 h �ִܰ�� ���ͽ�Ʈ��
		djikstra(s, dis_s);
		djikstra(g, dis_g);
		djikstra(h, dis_h);

		// s->f ==	s->g + g->h + h->f �� ���
		//			s->h + h->g + g->f
		for (int i = 0; i < t; i++) {
			int f = fin[i];

			int dis1 = dis_s[f];
			int dis2 = dis_s[g] + dis_g[h] + dis_h[f];
			int dis3 = dis_s[h] + dis_h[g] + dis_g[f];

			if (dis1 == min(dis2, dis3)) printf("%d ", f);
		}
		printf("\n");
	}
}