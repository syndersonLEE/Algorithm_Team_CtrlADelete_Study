/*Question 10844 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 101
using namespace std;
long long box[MAX_NUM][10];

int main() {
	int n;
	cin >> n;
	box[1][0] = 0;
	for (int i = 1;i <= 9;i++)
		box[1][i] = 1;
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j < 9;j++)
			box[i][j] = (box[i - 1][j - 1] + box[i - 1][j + 1])%1000000000;
		box[i][0] = box[i - 1][1];
		box[i][9] = box[i - 1][8];
	}
	long long ans = 0;
	for (int i = 0;i <= 9;i++) {
		ans += box[n][i];
		ans %= 1000000000;
	}
	cout << ans << endl;
}