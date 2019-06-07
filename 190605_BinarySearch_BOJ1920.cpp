// ���� 1920�� : �� ã��

/*
10�� �� ¥�� �迭�� 10�� �� Ž���Ϸ���
linear search �̿��ϸ� �ð� �ʰ��ϱ� binary search�� ����!

0. �ϴ� �����Ѵ�
1. left~right �� Ž��. mid = �����
2. ���� �����ִ� ���ڰ� mid���� �۴� -> left~mid Ž��
	ũ�� -> mid~right Ž��

*/


#include <stdio.h>
#include <algorithm>
using namespace std;

int A[100000];

int BS(int left, int right, int num) {

	int mid = (left + right) / 2;

	if (left <= right) {
		// left�� right ���� Ŀ���� �� ���� ���� �� �Ѵٴ� ��

		if (num < A[mid]) // mid�� �ִ� �� ���� ������
			return BS(left, mid - 1, num); // ���� ���� Ž��

		else if (num > A[mid])	// mid�� �ִ� �� ���� ũ��
			return BS(mid + 1, right, num); // ������ ���� Ž��

		else return 1; // mid�� �ִ� ���� �� ��! ã�Ҵ�!
	}

	return 0; // �� ã�Ҵ�
}

int main() {
	int N, M, num;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	scanf("%d", &M);

	// �ϴ� ����
	sort(A, A + N);
	
	while (M--) {
		scanf("%d", &num);
		printf("%d\n", BS(0, N - 1, num));
	}
	return 0;
}