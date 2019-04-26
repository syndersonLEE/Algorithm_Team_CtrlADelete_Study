#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int	N, temp; 
long long maxArea;

priority_queue <pair<long long, int>> pq;

int main() {
	ios::sync_with_stdio;
	cin >> N;
	while (N) {
		maxArea = 0;
		int bar[100005][2] = { 0 };
		for (int i = 1; i <= N; i++) {
			cin >> temp;
			pq.push(make_pair(temp, i));
		}

		while (!pq.empty()) {
			long long hei = pq.top().first;
			int index = pq.top().second;
			if (!bar[index - 1][0] && !bar[index + 1][0]) {
				bar[index][0] = index;
				bar[index][1] = index;
				maxArea = max(maxArea, hei);
			}
			else if (bar[index - 1][0] && bar[index + 1][0]) {
				bar[bar[index - 1][0]][1] = bar[index + 1][1];
				bar[bar[index + 1][1]][0] = bar[index - 1][0];
				maxArea = max(maxArea, hei * (bar[index + 1][1] - bar[index - 1][0] + 1));
			}
			else if (bar[index - 1][0]) {
				bar[index][0] = bar[index - 1][0];
				bar[index][1] = index;
				bar[bar[index - 1][0]][1] = index;
				maxArea = max(maxArea, hei * (bar[index][1] - bar[index][0] + 1));
			}
			else {
				bar[index][1] = bar[index + 1][1];
				bar[index][0] = index;
				bar[bar[index + 1][1]][0] = index;
				maxArea = max(maxArea, hei * (bar[index][1] - bar[index][0] + 1));
			}
			pq.pop();
		}

		cout << maxArea << "\n";
		cin >> N;
	}
}