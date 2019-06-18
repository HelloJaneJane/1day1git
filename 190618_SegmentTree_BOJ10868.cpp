// ���� 10868�� : �ּڰ�

/*
a��~b�� �� �ִ� ���� �� �ּڰ��� ã�ƾ� �Ѵ�
���׸�ƮƮ���� �̿��Ѵ�!

leaf���� == arr

arr[i] == i��~i���� �ִ� �� �� �ּڰ� �̶�� ����
(start�� i, end�� i) (s==e�� ���)
*/


#include <stdio.h>
#include <algorithm>
using namespace std;

// ��ũ�� �����صδ� �� �ڵ尡 �̻�����
#define mid (s+e)/2
#define Lchild node*2
#define Rchild node*2+1

#define INF 987654321

int n, m;
int arr[100010];
int tree[400040]; // Ʈ�� ũ��� arr�� 4�谡 �����ϴ�

// Ʈ�� �����
int init(int node, int s, int e) {
	// leaf��� �� �� arr���� �ְ� ������
	if (s == e)
		return tree[node] = arr[s];
	
	// s~e�� �ּڰ��� s~mid, mid+1~e �� �� ���� ��
	else
		return tree[node] = min(init(Lchild, s, mid), init(Rchild, mid + 1, e));
}

int a, b;

// ���� ���ϴ� ������ �ش��ϴ� �� ã��
int ans(int node, int s, int e) {
	// a~b�� ���� ���ϴ� ����, s~e�� �� �Լ��� ���� �����ִ� ����

	// �������� ����� ����
	if (e < a || b < s) return INF;
	
	// ������ ���� ���ϸ� tree�� ����ִ� �� �������
	if (a <= s && e <= b) return tree[node];

	// ������ �Ϻ� ���ϸ� ���� �ɰ��� �ٽ� Ȯ��
	return min(ans(Lchild, s, mid), ans(Rchild, mid + 1, e));
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);

	// Ʈ���� �� ó�� ���� �� 1��~n���� �ּڰ��� ���ϴ� root (����ȣ 1) ���� ����
	init(1, 1, n);
	

	while (m--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", ans(1, 1, n));
	}

	return 0;
}
