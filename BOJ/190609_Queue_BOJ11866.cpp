// ���� 11866�� : �����۽� ���� 0

/*
n���� ������ �ɾ��ִ� -> queue �̿��ؼ� pop-push �ݺ�
*/


#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, k;
queue<int> q;
vector<int> v;

int main() {
	scanf("%d%d", &n, &k);

	// �ϴ� 1~n�� ť�� �ִ´�
	for (int i = 1; i <= n; i++) q.push(i);

	// ��ΰ� ���õ� ������ (== ť�� �� ������) �ݺ�
	while (!q.empty()) {
		// 1ȸ �ݺ� �� k�� Ž��

		// ó������ k-1���� �տ� �� ���� �ڷ� �ִ´� (push�� pop)
		for (int i = 0; i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		// k�� °���� �׳� ����
		v.push_back(q.front()); // ���߿� ����� ���Ϳ� ����
		q.pop();
	}

	// ����� �� �ǵ�
	for (int i = 0; i < n; i++) {
		if (i == 0) printf("<"); // �� ó��
		printf("%d", v[i]);			
		if (i == n - 1) printf(">"); // �� ������
		else printf(", ");
	}
}