// 백준 1059번 : 수2

/*
쉬운 거 같은데 if문 케이스를 어떻게 나눠야 할지랑
수식을 한 줄로 어떻게 쓸지 생각하는 게 오래 걸렸다
심지어 예외 케이스도 있더라..
*/


#include <stdio.h>
#include <algorithm>
using namespace std;

int lucky[1010];
int l, n;

int main() {
	scanf("%d", &l);
	for (int i = 1; i <= l; i++) scanf("%d", &lucky[i]);
	sort(lucky, lucky + l + 1);	// 일단 정렬한다
	
	/*
	lucky set은 숫자 l개
	1 base로 하고 맨 앞에 0을 포함시켜줘야한다
	왜냐면 예를들어 lucky=<3 7> 일 때 n=2면 [1~2]가 있어서 답이 1이거든..
	*/
	
	scanf("%d", &n);

	for (int i = 0; i < l; i++) {
		// n이 lucky의 연속된 두 수 사이에 들어가는 경우가 있다면
		if (lucky[i] < n && n < lucky[i + 1]) {

			/*
			n을 포함하는 범위가 [a~b] 라고 하면
			a가 될 수 있는 수 : lucky[i]+1 부터 n까지	-> 총 n-lucky[i] 개
			b가 될 수 있는 수 : n부터 lucky[i+1]-1 까지	-> 총 lucky[i+1]-n 개
			이때 a랑 b 둘 다 n이 되는 경우 한 가지는 제외

			그럼 총 개수는 두 수 곱하고 1 뺀 값
			*/

			printf("%d", (n - lucky[i])*(lucky[i + 1] - n) - 1);
			return 0;
		}
	}
	// lucky를 끝까지 돌았는데 저 경우에 해당이 안 된다면
	// lucky의 원소랑 겹쳤다는 뜻이니까 답은 0
	printf("0");

}