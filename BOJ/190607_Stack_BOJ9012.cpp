// 백준 9012번 : 괄호

/*
짝꿍 찾기는 스택 이용하는 게 편함!

'('면 스택에 넣고 ')'면 하나씩 뺀다

짝꿍이 안 맞는 경우
1. ')' 가 더 있어서 pop이 불가능
2. '(' 가 더 있어서 마지막에 남음
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
		
		// str 글자 앞에서부터 하나씩 확인
		for (int i = 0; i < l; i++) {

			// '('면 넣는다
			if (str[i] == '(') s.push('(');
			
			// ')'면 뺀다
			else {
				// 안 맞으면 false
				if (s.empty()) ans = false;
				else s.pop();
			}
		}
		// 확인 끝났는데 남았으면 false
		if (!s.empty()) ans = false;

		if (ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}