/*Question 11722 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 1003
using namespace std;

int box[MAX_NUM];
int cost[MAX_NUM];


int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> cost[i];
		box[i] = 1;
	}
	for (int i = n;i >= 1;i--) {
		for (int j = n;j > i;j--) {
			if (cost[i]>cost[j])
				box[i] = max(box[i], box[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		ans = max(ans, box[i]);
	cout << ans << endl;
}