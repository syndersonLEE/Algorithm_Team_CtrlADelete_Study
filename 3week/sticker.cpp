/*Question 9465 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 1000000
using namespace std;
long long box[MAX_NUM][3];
int cost[MAX_NUM][2];

int main() {
	int a;
	cin >> a; 
	while (a--) {
		int n;
		cin >> n;
		for (int i = 1;i <= n;i++)
			cin >> cost[i][0];
		for (int i = 1;i <= n;i++)
			cin >> cost[i][1];
		box[1][0] = 0;
		box[1][1] = cost[1][0];
		box[1][2] = cost[1][1];

		for (int i = 2;i <= n;i++) {
			box[i][0] = max({ box[i - 1][0],box[i - 1][1],box[i - 1][2] });
			box[i][1] = max(box[i - 1][0], box[i - 1][2]) + cost[i][0];
			box[i][2] = max(box[i - 1][0], box[i - 1][1]) + cost[i][1];
		}
		long long ans = max({ box[n][0] , box[n][1] , box[n][2] });
		cout << ans << endl;
	}
	return 0;
}