#include<stdio.h>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int n, l, fntVal, temp, cnt = 0;

int main() {
	scanf("%d %d", &n, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		pq.push(temp);
	}

	while (!pq.empty()) {
		fntVal = pq.top();
		pq.pop();
		while (!pq.empty() && (pq.top() - fntVal < l)) {
			pq.pop();
		}
		cnt++;
	}
	printf("%d\n", cnt);
}