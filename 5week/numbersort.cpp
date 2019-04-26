/*Question 11650 좌표 정렬하기 in BaekJoon Online Judge
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
		cin >> box[i].first >> box[i].second;
	sort(box.begin(), box.end());
	for (int i = 0;i < n;i++)
		cout << box[i].first << " " << box[i].second << "\n";
	return 0;
}