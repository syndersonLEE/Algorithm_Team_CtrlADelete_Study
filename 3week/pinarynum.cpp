/*Question 2193 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 91
using namespace std;
long long box[MAX_NUM][2];

int main() {
	int n;
	cin >> n;
	box[1][0] = 0;
	box[1][1] = 1;
	for (int i = 2;i <= n;i++) {
		box[i][0] = box[i - 1][0] + box[i - 1][1];
		box[i][1] = box[i - 1][0];
	}
	long long ans = box[n][0] + box[n][1];
	cout << ans << endl;
}