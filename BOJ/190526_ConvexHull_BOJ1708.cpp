// ALOHA ��޹� 6���� - ���ϲ��� ���� / ���� 1708��

/*
Convex Hull ���� Ǫ�� ����
1) ��ǥ ������ �����ؼ� ���� ���� �ź��� �� : Monotone Chain
2) x��ǥ ���� ���� ���� ���� ���� ������ ���� : Graham Scan

���� ���� �̿��ϴ� ����� ü�� ������� Ǯ����
1. ���ÿ��� ���� �� ���̶� ���� ���� ���� �ִ� ���� CCW�Ѵ�
2. �����ϸ� ���� ���� �ְ�, �� �����ϸ� ���� �� �ϳ� ���� �ٽ� CCW�Ѵ�
(������ ������ ��� pop �ݺ�)
3. ������ ������ �� ������ ���� �ȿ� �����ִ� �͵� �� ���� �� �����̶�� ��
�׷��� �Ʒ� ����, �� ���� ������ ���� ���� �ϼ�!
*/



#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;


// x, y ��ǥ�� pair�� �� �Ŵϱ� �� �򰥸��� ��ũ�� �����ص�
#define x first
#define y second


// Counter Clock Wise
// A, B, C �� �� ���� �� �ݽð� �����̸� +, �ƴϸ� - �� ���� (0�̸� ����)
long long ccw(pair<int, int> A, pair<int, int> B, pair<int, int> C) {
	return 1LL * (B.x - A.x)*(C.y - A.y) - 1LL * (B.y - A.y)*(C.x - A.x);
}
// 1LL ���ϸ� �շ� ������ ��ȯ ��


int n;

pair<int, int> arr[100010];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d%d", &arr[i].x, &arr[i].y);
	sort(arr, arr + n); // ��ǥ ������ �����Ѵ�

	// low�� x��ǥ ������->ū��, up�� ū��->������ ������ Ȯ���ϱ�

	// �Ʒ�(Lower) ����
	stack< pair<int, int> > L;
	L.push(arr[0]);
	L.push(arr[1]);
	for (int i = 2; i != n; i++) {
		pair<int, int> now = arr[i]; // ���� ���� ���� ��
		pair<int, int> top, top2; // ���� �ȿ� �ִ� ���� �� �� (top�� �� ��, top2�� �� ��° �� ��)
		do {
			top = L.top();
			L.pop();
			if (L.empty()) { break; }
			top2 = L.top();
		} while (ccw(top2, top, now) <= 0); // �� ���� CCW ������ �� ���� �ݺ�
		L.push(top);
		L.push(now);
	}

	// ��(Upper) ����
	stack< pair<int, int> > U;
	U.push(arr[n - 1]);
	U.push(arr[n - 2]);
	for (int i = n - 1; i >= 0; i--) {
		pair<int, int> now = arr[i];
		pair<int, int> top, top2;
		do {
			top = U.top();
			U.pop();
			if (U.empty()) { break; }
			top2 = U.top();
		} while (ccw(top2, top, now) <= 0);
		U.push(top);
		U.push(now);
	}

	int cnt = 0;
	while (!L.empty()) { // �Ʒ� ������ ���ϴ� �� ���� ����
		cnt++;
		L.pop();
	}
	while (!U.empty()) { // �� ������ ���ϴ� �� ���� ����
		cnt++;
		U.pop();
	}

	printf("%d", cnt - 2); // �� �� ��ġ�� �� �� ���� �� ���� ���ֱ�
}