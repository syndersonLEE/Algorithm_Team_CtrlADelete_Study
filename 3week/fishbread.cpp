/*Question 11052 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 10001
using namespace std;
int box[MAX_NUM];
int cost[MAX_NUM];
int fishbread(int a) {
	if (a == 0)
		return 0;
	if (box[a] != -1)
		return box[a];
	else {
		for (int i = 1;i <= a;i++)
			box[a] = max(box[a], fishbread(a-i) + cost[i]);
		return box[a];
	}
}
int main() {
	int n;
	cin >> n;
	fill(box, box + n +1, -1);
	for (int i = 1;i <= n;i++)
		cin >> cost[i];
	cout << fishbread(n) << endl;
}
/*
*/