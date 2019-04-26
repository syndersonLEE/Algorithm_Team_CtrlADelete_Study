#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

int numLines, lineF, lineB;
long long ans = 0;
int temp1, temp2;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
	scanf("%d", &numLines);
	for (int i = 0; i < numLines; i++) {
		scanf("%d %d", &temp1, &temp2);
		pq.push(make_pair(temp1, temp2));
	}

	while (!pq.empty()) {
		lineF = pq.top().first;
		lineB = pq.top().second;
		pq.pop();
		while (!pq.empty()&&(lineB >= pq.top().first)) {
			if (pq.top().second > lineB) {
				lineB = pq.top().second;
			}
			pq.pop();
		}
		ans += (lineB - lineF);
	}

	printf("%lld\n", ans);
}