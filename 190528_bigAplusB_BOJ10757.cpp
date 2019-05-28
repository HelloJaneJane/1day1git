// ���� 10757�� : ū �� A+B
// ���� �ʹ� ũ�ϱ� ���ڿ��� �޾Ƽ� �����ϱ�


#include <stdio.h>
#include <string.h>
char str1[10010];
char str2[10010];

int num[10010];

int main() {
	scanf("%s%s", str1, str2);

	int l1 = strlen(str1);
	int l2 = strlen(str2);

	// �� ���ڿ��� ���� �� ���� ��, ū �� 
	int min = (l1 > l2 ? l2 : l1);
	int max = (l1 > l2 ? l1 : l2);

	// �� �ں��� ���� ���� �� ���� : ���Ѵ�. 10 �Ѿ�� �ڸ� �ø���
	for (int i = 0; i < min; i++) {
		num[i] += (str1[l1 - 1 - i] - '0') + (str2[l2 - 1 - i] - '0');
		if (num[i] >= 10) {
			num[i] -= 10;
			num[i + 1]++;
		}
	}
	// ���� �� �������� ū �� ���� : �׳� �ִ´�
	for (int i = min; i < max; i++) {
		if (max == l1) num[i] += (str1[l1 - 1 - i] - '0');
		else if (max == l2) num[i] += (str2[l2 - 1 - i] - '0');
		if (num[i] >= 10) {
			num[i] -= 10;
			num[i + 1]++;
		}
	}

	int size = (num[max] == 0 ? max : max + 1);

	// num �ڿ������� ���
	for (int i = size - 1; i >= 0; i--) printf("%d", num[i]);

	return 0;
}