/*Question 11055 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 1001
using namespace std;

int box[MAX_NUM];
int cost[MAX_NUM];

int sol(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (box[n] != -1)
		return box[n];
	else {
		for (int i = 0; i <= n - 1; i++)
			if (cost[n]>cost[i])
				box[n] = max(box[n], sol(i) + 1);
		return box[n];
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> cost[i];
	fill(box, box + n + 1, -1);
	cout << sol(n) << endl;
}