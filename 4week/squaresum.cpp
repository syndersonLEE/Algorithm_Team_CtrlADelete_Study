/*Question 1699 Á¦°ö¼öÀÇ ÇÕ in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 100002
using namespace std;

int box[MAX_NUM];
int sq_sum(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	if (box[n] != -1)
		return box[n];
	else {
		int i = 1;
		while ((i+1)*(i+1) <= n)
			i++;

		int min_num = n;
		for (int j = i;j > 0;j--)
			min_num = min(min_num, sq_sum(n - (j*j))+1);
		return box[n] = min_num;
	}
}

int main() {
	int n;
	cin >> n;
	fill(box, box + n + 1,-1);
	int ans = sq_sum(n);
	cout << ans << endl;
}