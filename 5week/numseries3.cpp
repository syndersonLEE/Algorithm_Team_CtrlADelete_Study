/*Question 10989 수 정렬하기in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	long long n;
	cin >> n;
	int box[10001] = { 0 };
	int a;
	for (int i = 0;i < n;i++) {
		cin >> a;
		box[a]++;
	}
	for (int i = 0;i < 10001; i++) {
		while (box[i]--)
			cout << i << "\n";
	}
	return 0;
}