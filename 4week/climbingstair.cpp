/*Question 2579 계단오르기 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 302
using namespace std;

long long box[MAX_NUM][3];
int cost[MAX_NUM];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> cost[i];
	}
	for (int i = 0;i < 3;i++)
		box[0][i] = 0;

	for (int i = 1;i <= n;i++) {
		box[i][0] = max(box[i-1][1],box[i-1][2]);
		box[i][1] = box[i-1][0] + cost[i];
		box[i][2] = box[i-1][1] + cost[i];
	}
	
	long long ans;
	ans = max(box[n][1], box[n][2]);
	cout << ans << endl;
}