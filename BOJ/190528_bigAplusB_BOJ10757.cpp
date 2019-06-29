// 백준 10757번 : 큰 수 A+B
// 수가 너무 크니까 문자열로 받아서 연산하기


#include <stdio.h>
#include <string.h>
char str1[10010];
char str2[10010];

int num[10010];

int main() {
	scanf("%s%s", str1, str2);

	int l1 = strlen(str1);
	int l2 = strlen(str2);

	// 두 문자열의 길이 중 작은 거, 큰 거 
	int min = (l1 > l2 ? l2 : l1);
	int max = (l1 > l2 ? l1 : l2);

	// 맨 뒤부터 길이 작은 거 까지 : 더한다. 10 넘어가면 자리 올린다
	for (int i = 0; i < min; i++) {
		num[i] += (str1[l1 - 1 - i] - '0') + (str2[l2 - 1 - i] - '0');
		if (num[i] >= 10) {
			num[i] -= 10;
			num[i + 1]++;
		}
	}
	// 작은 거 다음부터 큰 거 까지 : 그냥 넣는다
	for (int i = min; i < max; i++) {
		if (max == l1) num[i] += (str1[l1 - 1 - i] - '0');
		else if (max == l2) num[i] += (str2[l2 - 1 - i] - '0');
		if (num[i] >= 10) {
			num[i] -= 10;
			num[i + 1]++;
		}
	}

	int size = (num[max] == 0 ? max : max + 1);

	// num 뒤에서부터 출력
	for (int i = size - 1; i >= 0; i--) printf("%d", num[i]);

	return 0;
}