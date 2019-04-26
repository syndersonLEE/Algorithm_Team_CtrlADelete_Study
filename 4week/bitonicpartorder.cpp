/*Question 11054 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 1003
using namespace std;

int asc[MAX_NUM];
int des[MAX_NUM];
int cost[MAX_NUM];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> cost[i];
		asc[i] = 1;
		des[i] = 1;
	}
	for (int i = 2;i <= n;i++) {
		for (int j = 1;j < i;j++) {
			if (cost[i]>cost[j])
				asc[i] = max(asc[i], asc[j] + 1);
		}
	}
	for (int i = n;i >= 1;i--) {
		for (int j = n;j > i;j--) {
			if (cost[i]>cost[j])
				des[i] = max(des[i], des[j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;i++)
		ans = max(ans, asc[i]+des[i]);
	cout << ans-1 << endl;
}