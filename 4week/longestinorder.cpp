/*Question 11053 in BaekJoon Online Judge
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
	for (int i = 1;i <= n;i++)
		cin >> cost[i];
	fill(box, box + n + 2, 1);
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j < i;j++) {
			if(cost[i]>cost[j])
				box[i] = max(box[i], box[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		ans = max(ans, box[i]);
	cout << ans << endl;
}