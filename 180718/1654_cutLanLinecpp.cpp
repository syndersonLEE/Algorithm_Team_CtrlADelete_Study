//Solved By SANGYUNLEE

#include<stdio.h>
#include<algorithm>

using namespace std;

int n, k, maxLen = 0;
int len[10001];

void evalMaxLen();

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &len[i]);
		maxLen = max(maxLen, len[i]);
	}

	evalMaxLen();
}

void evalMaxLen() {
	long long left = 1, right = maxLen, mid, numLine, ans;
	while (left <= right) {
		mid = (left + right) / 2;
		numLine = 0;
		for (int i = 0; i < n; i++) {
			numLine += (len[i] / mid);
		}

		if (numLine < k) {
			right = mid - 1;
		}
		else {
			if (numLine >= k) {
				ans = mid;
			}
			left = mid + 1;
		}
	}

	printf("%d\n", ans);
}