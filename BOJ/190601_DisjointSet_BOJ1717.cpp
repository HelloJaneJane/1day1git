// ALOHA �˰���� 8���� ���� �غ�


/*
 Disjoint Set - Union=Find �˰���
*/

#include <stdio.h>

int n, m;
int p[1000010];


// root ã�� �� ���� ��� ������
int find(int x) { 
	if (p[x] == x) return x;
	else return p[x] = find(p[x]); // ��� ����
}

void uni(int a, int b) {
	if (find(a) != find(b)) // �ٸ� ���տ� ���ϸ�
		p[find(a)] = find(b); // a�� root�� b�� root�� ���δ�
}

int main() {
	scanf("%d%d", &n, &m);

	// �ϴ��� ���� parent == �� ��� �ʱ�ȭ
	for (int i = 1; i <= n; i++) p[i] = i;

	while (m--) {
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);

		if (cmd) { // 1�� ��
			// root�� ������ YES
			if (find(a) == find(b)) printf("YES\n");
			// �ƴϸ� NO
			else printf("NO\n");
		}
		else { // 0�� ��
			// ���� ���տ� ���ϵ��� Union �ϱ�
			uni(a, b);
		}
	}
	return 0;
}