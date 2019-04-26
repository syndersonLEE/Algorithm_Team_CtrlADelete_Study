/*Question 11057 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 1001
using namespace std;
int box[MAX_NUM][10];

int main() {
	int n;
	cin >> n;
	for (int i = 0;i <= 9;i++)
		box[1][i] = 1;
	for (int i = 2;i <= n;i++) {
		for (int j = 0;j <= 9;j++) {
			box[i][j] = 0;
			for (int k = 0;k <= j;k++)
				box[i][j] += box[i - 1][k]%10007;
		}
	}
	int ans = 0;
	for (int i = 0;i <= 9;i++)
		ans += box[n][i];
	cout << ans % 10007 << endl;
}
/*
%10007
*/