/*Question 1377 버블소트 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int n, m;
	scanf("%d", &n);
	vector<pair<int, int>> box(n);
	for (int i = 0;i < n;i++) {
		scanf("%d", &box[i].first);
		box[i].second = i;
	}
	sort(box.begin(), box.end());
	int dist_max = 1;
	for (int i = 0;i < n;i++) {
		dist_max = max(dist_max, box[i].second-i+1);
	}
	printf("%d\n", dist_max);

	return 0;
}