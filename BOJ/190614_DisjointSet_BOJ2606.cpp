// ���� 2606�� : ���̷���

/*
DFS BFS �ε� Ǯ �� ���� �� ����.. �з����� �÷��̵�� ���ִµ�
���� ���Ͼ����ε�� �ϰ� �; �ߴµ�
�ټ� ���̳� Ʋ�Ƚ��ϴ� ���ļ� �ܿ� ���� �Ф�
*/


#include <stdio.h>

int V, E;

int root[105];

int find(int x) {
	if (root[x] == x) return x;
	else return root[x] = find(root[x]);
	///////////////////////////////////
	// else �ٿ� 'return' �� �Ἥ ��� Ʋ�� �ſ��� ^^... �ٵ� �������� �̷� �� �־���...
}

int main() {
	scanf("%d%d", &V, &E);

	// �ʱ�ȭ : ���� ��Ʈ�� ��
	for (int i = 1; i <= V; i++) root[i] = i;

	for (int i = 0; i < E; i++) {
		int a, b;
		scanf("%d%d", &a, &b);

		if (find(a) != find(b)) {
		// a�� b�� �ٸ� �����̸� ���� �����ֱ�
			root[find(a)] = find(b);
		}
	}

	int cnt = 0;
	for (int i = 2; i <= V; i++) {
		// 1�̶� ���� ���տ� �ִ� �� ���� ����
		if (find(i) == find(1)) cnt++;
	}
	printf("%d", cnt);

}