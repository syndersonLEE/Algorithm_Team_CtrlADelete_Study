/*Question 2133 타일 채우기 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 31
using namespace std;

int box[MAX_NUM];
int tile_fill(int n) {
	if (n == 0)
		return 1;
	if (box[n] != -1)
		return box[n];
	else {
		box[n] = 3 * tile_fill(n - 1);
		for (int i = 0;i <= n - 2;i++)
			box[n] += 2 * tile_fill(i);
		return box[n];
	}
}

int main() {
	int n;
	cin >> n;
	fill(box, box + n + 1, -1);
	if (n % 2)
		cout << 0 << endl;
	else {
		int ans = tile_fill(n / 2);
		cout << ans << endl;
	}
}