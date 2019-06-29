// ALOHA ��޹� 7���� - ��Ʈ��ũ�÷ο� ���� / ���� 2188��

/*
��Ʈ��ũ�÷ο츦 �ϱ� ���� �̺и�Ī�� �˾ƾ���!
: �̺� �׷������� �ִ�� �� ������ ��Ī�� �� �ִ��� dfs�� ã��

1������ n������ ���ʷ� ��Ī��Ŵ
��ġ�� �� ������ �� ���� �� �ٸ��ɷ� ��Ī��ų �� �ִ��� Ȯ���غ�
�� �Ǹ� �´� ��Ī �Ұ�. �Ǹ� �׷��� ��Ī�ϰ� �Ѿ��
*/


#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <string.h>
using namespace std;

int n, m; // 1~n�� 1~m�� ����

vector<int> map[210]; // ���� �����صδ� ��������Ʈ

bool visit[210]; // dfs �� �� �湮 ���� �����ص�
int match[210]; // ������ ��Ī�Ǿ��ִ��� �����ص� (��Ī �� �Ǿ������� 0)


bool dfs(int a) {
	visit[a] = true; // �湮�ߴٰ� üũ�صα�

	int siz = map[a].size();
	for (int i = 0; i < siz; i++) { // map[a]�� ����ִ� �� �ϳ��� Ȯ��
		int b = map[a][i];
		
		/*	1) b�� ���� ��Ī�� �� �Ǿ��ִ� ���
			2) b�� ��Ī�� �Ǿ��ִµ�
			 �� ��Ī�� �� (== match[b]) �� ���� �湮�� �� �߰�
			 �װŸ� dfs������ �� �ٸ� �ֶ� ��Ī�� �Ǵ� ���*/
		if (!match[b] || (!visit[match[b]] && dfs(match[b]))) {
			match[b] = a; // a�� ��Ī�ϱ�
			return true; // ��Ī �����ϸ� true ����
		}
	}

	// �ϳ��� ��Ī�Ǵ� �� ������ false ����
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int s;
		scanf("%d", &s);
		for (int j = 0; j < s; j++) {
			int a;
			scanf("%d", &a);
			map[i].push_back(a);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit));
		if (dfs(i)) cnt++; // cnt : ��Ī ���� ����
	}

	printf("%d", cnt);

}