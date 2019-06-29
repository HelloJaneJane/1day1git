// ���� 10026�� : ���ϻ���

/*
map : RGB �� �ϳ�
���ϻ����� ������ ���� ���ڳ����� �����
���ϻ����� ������ ���� ���ڳ��� + R�̶� G�� �پ������� �����

BFS�� ������
1. n^2���� ĭ�� �� Ž��
2. �湮���� ���� ĭ�̸� ť�� �ִ´�
3. ť�� ����ִ� ĭ�� ������ ĭ���� Ȯ��
 -> 1) ���ϻ��� ���� �� : ���� �湮 X && ���� ���ڸ�
	2) ���ϻ��� ���� �� : ���� �湮 X && ���� ���� || �ϳ��� B���� ������
 �湮 üũ + ť�� �ֱ�

 -> �׷� ť�� �� ������ �ݺ��ϸ� ������ �Ŷ� ���� ������ �� �� Ȯ���ϰ� ��
 'ť �ݺ�'<< �� ������ Ƚ���� �� ������ ��
*/


#include <stdio.h>
#include <queue>
#include <iostream>
using namespace std;

int n;

char map[105][105];

// �ʱ�ȭ�ϱ� �����Ƽ� 1�� ��� / 2�� ��� ������ �����ع���
bool visit1[105][105];
queue<pair<char, pair<int, int> > > qu1;
bool visit2[105][105];
queue<pair<char, pair<int, int> > > qu2;

// �� ���� Ž���ϴ� ��
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

// ���ϻ����� �� �� ���ڰ� ���� ���ƺ��̴��� �˷��ִ� �Լ�
bool same2(char c1, char c2) {
	// �ϳ��� B�̸� �ٸ��� ���δ� (�������� �� ����)
	if ((c1 == 'B' && c2 != 'B') || (c1 != 'B' && c2 == 'B')) return false;
	return true;
}


int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", map[i]);
	}

	// ���ϻ����� �ƴ� ��� : 1�� ���
	int ans1 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			// �湮 �� �� �� -> �� ������ ����
			if (!visit1[i][j]) {
				qu1.push({ map[i][j],{i,j} });
				visit1[i][j] = true;
				ans1++; // ������ ��
			}

			// ť �ݺ�
			while (!qu1.empty()) {
				char nowChar = qu1.front().first;
				int nowY = qu1.front().second.first;
				int nowX = qu1.front().second.second;
				qu1.pop();

				for (int i = 0; i < 4; i++) {
					int toY = nowY + dy[i];
					int toX = nowX + dx[i];
					char toChar = map[toY][toX];

					// ���� ����� ����
					if (toY < 0 || n <= toY || toX < 0 || n <= toX) continue;

					// �湮 �� �߰� && ���ڰ� ������
					if (!visit1[toY][toX] && toChar == nowChar) {
						qu1.push({ toChar,{toY,toX} });
						visit1[toY][toX] = true;
					}
				}
			}
		}
	}

	// ���ϻ����� �´� ��� : 2�� ���
	int ans2 = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			if (!visit2[i][j]) {
				qu2.push({ map[i][j],{i,j} });
				visit2[i][j] = true;
				ans2++;
			}

			while (!qu2.empty()) {
				char nowChar = qu2.front().first;
				int nowY = qu2.front().second.first;
				int nowX = qu2.front().second.second;
				qu2.pop();

				for (int i = 0; i < 4; i++) {
					int toY = nowY + dy[i];
					int toX = nowX + dx[i];
					char toChar = map[toY][toX];

					if (toY < 0 || n <= toY || toX < 0 || n <= toX) continue;

					// ���ϻ��� �����ϱ� ���ڰ� �׳� ������ ���� (1�� ���� ���⸸ �ٸ�)
					if (!visit2[toY][toX] && same2(toChar, nowChar)) {
						qu2.push({ toChar,{toY,toX} });
						visit2[toY][toX] = true;
					}
				}
			}
		}
	}


	printf("%d %d", ans1, ans2);
}