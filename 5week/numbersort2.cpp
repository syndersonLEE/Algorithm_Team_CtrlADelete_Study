/*Question 11651 좌표 정렬하기2 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<vector>
#include<algorithm>
#define MAX_NUM 1000002

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> box(n);
	for (int i = 0;i < n;i++)
		cin >> box[i].second >> box[i].first; // y,x
	sort(box.begin(), box.end());
	for (int i = 0;i < n;i++)
		cout << box[i].second << " " << box[i].first << "\n";
	return 0;
}