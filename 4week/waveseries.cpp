/*Question 9461 파도반 수열 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 102
using namespace std;

long long box[MAX_NUM] = { 0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9 };
long long wave(int n) {
	if (n <= 10)
		return box[n];
	if (box[n] != 0)
		return box[n];
	else {
		box[n] = wave(n - 1) + wave(n - 5);
		return box[n];
	}
}

int main() {
	int a,n;
	cin >> a;
	while (a--) {
		cin >> n;
		cout << wave(n) << endl;
	}
}