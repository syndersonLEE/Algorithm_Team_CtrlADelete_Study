#include<iostream>
#include<algorithm>

using namespace std;

long long num[100002], N, maxNum, cur, ans = 0;

int main() {
	ios::sync_with_stdio;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}

	for (int i = 1; i <= N; i++) {
		maxNum = num[i];
		cur = 1;
		for (int j = i + 1; j <= N; j++) {
			if (maxNum + 1 == num[j]) {
				cur++;
				maxNum++;
			}
		}
		ans = max(ans, cur);
	}
	cout << ans << "\n";
}