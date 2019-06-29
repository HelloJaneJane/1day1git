// ���� 9012�� : ��ȣ

/*
¦�� ã��� ���� �̿��ϴ� �� ����!

'('�� ���ÿ� �ְ� ')'�� �ϳ��� ����

¦���� �� �´� ���
1. ')' �� �� �־ pop�� �Ұ���
2. '(' �� �� �־ �������� ����
*/

#include <stdio.h>
#include <stack>
#include <string.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {

		std::stack<char> s;
		bool ans = true;
		char str[55];
		scanf("%s", str);
		int l = strlen(str);
		
		// str ���� �տ������� �ϳ��� Ȯ��
		for (int i = 0; i < l; i++) {

			// '('�� �ִ´�
			if (str[i] == '(') s.push('(');
			
			// ')'�� ����
			else {
				// �� ������ false
				if (s.empty()) ans = false;
				else s.pop();
			}
		}
		// Ȯ�� �����µ� �������� false
		if (!s.empty()) ans = false;

		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}