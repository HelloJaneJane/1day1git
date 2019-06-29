// 2019 SCPC 1������ - 1�� : ������ ������

/*
¦�� : 2�� ������ / Ȧ�� : 1�� ���Ѵ�
1�� ������� �� ���� �۾��� �ؾ��ұ�?

3->4->2->1	: dp[3] = 3 = 1+dp[4]
4->2->1		: dp[4] = 2 = 1+dp[2]

i�� Ȧ�� : dp[i]=1+dp[i+1]
i�� ¦�� : dp[i]=1+dp[i/2]

����Լ��� dp�迭�� ä���
*/

/*
�ð��ʰ� ������ �ټ� ���̳� Ʋ�ȴ�
�� �� �Ÿ��� �� �غ��ٰ�
�ᱹ ���׸�Ʈ Ʈ���� Ǯ����
*/

#include <iostream>
#include <stdio.h>
using namespace std;

#define ll long long
#define mid (s+e)/2
#define Lchild node*2
#define Rchild node*2+1

ll Answer;
int n1, n2;

int dp[1000010] = { 0,0,1 };
ll tree[4000040];

int fill(int i) {
	if (i == 1) return 0; // �̰� ���� �� �س����� 1->2�� ��������
	if (dp[i]) return dp[i];

	if (i % 2 == 0) { // ¦��
		return dp[i] = 1 + fill(i / 2);
	}
	else { // Ȧ��
		return dp[i] = 1 + fill(i + 1);
	}
}

ll init(int node, int s, int e) {
	if (s == e) // leaf��� �� ��
		return tree[node] = dp[s];
	else
		return tree[node] = init(Lchild, s, mid) + init(Rchild, mid + 1, e);
}

// s~e : ���� �����ִ� ����,  l~r : ���ؾ��ϴ� ����
ll sum(int node, int s, int e, int l, int r) {
	if (e < l || r < s) // s~e�� ���� ���� �� �� ��
		return 0;
	if (l <= s && e <= r) // s~e�� ���� ������ ��
		return tree[node];
	return sum(Lchild, s, mid, l, r) + sum(Rchild, mid + 1, e, l, r);
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, test_case;

	cin >> T;

	// dp�迭�� �̸� ä�����´�
	// �Ųٷ� �ϴ� �� �Լ� ȣ�� Ƚ���� ����
	for (int i = 1000000; i >= 3; i--) {
		dp[i] = fill(i);
	}

	init(1, 1, 1000000);

	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;

		cin >> n1 >> n2;

		Answer = sum(1, 1, 1000000, n1, n2);

		cout << "Case #" << test_case + 1 << '\n';
		cout << Answer << '\n';
	}

	return 0;
}