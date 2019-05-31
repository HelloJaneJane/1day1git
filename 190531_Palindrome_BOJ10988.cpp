// 백준 10988번 : 팰린드롬인지 확인하기

/*
팰린드롬하면 재귀함수!
left, right 가 똑같으면 left+1, right-1 확인하기
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