// ���� 10988�� : �Ӹ�������� Ȯ���ϱ�

/*
�Ӹ�����ϸ� ����Լ�!
left, right �� �Ȱ����� left+1, right-1 Ȯ���ϱ�
*/


#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

string s;

int is_palin(int left, int right) {
	if (left >= right) return 1;

	if (s[left] == s[right]) return is_palin(left + 1, right - 1);
	else return 0;
}

int main() {
	cin >> s;
	int len = s.length();

	cout << is_palin(0, len - 1);
}