// ���� 1059�� : ��2

/*
���� �� ������ if�� ���̽��� ��� ������ ������
������ �� �ٷ� ��� ���� �����ϴ� �� ���� �ɷȴ�
������ ���� ���̽��� �ִ���..
*/


#include <stdio.h>
#include <algorithm>
using namespace std;

int lucky[1010];
int l, n;

int main() {
	scanf("%d", &l);
	for (int i = 1; i <= l; i++) scanf("%d", &lucky[i]);
	sort(lucky, lucky + l + 1);	// �ϴ� �����Ѵ�
	
	/*
	lucky set�� ���� l��
	1 base�� �ϰ� �� �տ� 0�� ���Խ�������Ѵ�
	�ֳĸ� ������� lucky=<3 7> �� �� n=2�� [1~2]�� �־ ���� 1�̰ŵ�..
	*/
	
	scanf("%d", &n);

	for (int i = 0; i < l; i++) {
		// n�� lucky�� ���ӵ� �� �� ���̿� ���� ��찡 �ִٸ�
		if (lucky[i] < n && n < lucky[i + 1]) {

			/*
			n�� �����ϴ� ������ [a~b] ��� �ϸ�
			a�� �� �� �ִ� �� : lucky[i]+1 ���� n����	-> �� n-lucky[i] ��
			b�� �� �� �ִ� �� : n���� lucky[i+1]-1 ����	-> �� lucky[i+1]-n ��
			�̶� a�� b �� �� n�� �Ǵ� ��� �� ������ ����

			�׷� �� ������ �� �� ���ϰ� 1 �� ��
			*/

			printf("%d", (n - lucky[i])*(lucky[i + 1] - n) - 1);
			return 0;
		}
	}
	// lucky�� ������ ���Ҵµ� �� ��쿡 �ش��� �� �ȴٸ�
	// lucky�� ���Ҷ� ���ƴٴ� ���̴ϱ� ���� 0
	printf("0");

}