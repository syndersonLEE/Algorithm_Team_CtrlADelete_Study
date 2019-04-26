/*Question 10451 순열 사이클 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		int m;
		cin >> m;
		vector <int> box(m + 1,0);
		vector <bool> check(m + 1, false);
		for (int j = 1; j <= m;j++)
			cin >> box[j];
		int count = 0;
		for (int j = 1; j <= m;j++) {
			int k = j;
			while (!check[k]) {
				check[k] = true;
				if (!check[box[k]])
					k = box[k];
				else {
					count++;	break;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}