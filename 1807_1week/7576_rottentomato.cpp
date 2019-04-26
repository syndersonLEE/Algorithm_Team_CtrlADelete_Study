//solved by SANGYUNLEE

#include<stdio.h>
#include<queue>

using namespace std;

queue<pair<int, int>> q;

int m, n;
int arr[1000][1000];

void bfs(int days) {
	int queueSize = q.size();
	bool checkProceed = false;
	bool checkZero = false;
	for (int i = 0; i < queueSize; i++) {
		int queueFirst = q.front().first;
		int queueSecond = q.front().second;
		q.pop();
		if (queueFirst - 1 >= 0 && arr[queueFirst - 1][queueSecond] == 0) {
			arr[queueFirst - 1][queueSecond] = 1;
			q.push(make_pair(queueFirst - 1, queueSecond));
			checkProceed = true;
		}
		if (queueSecond - 1 >= 0 && arr[queueFirst][queueSecond - 1] == 0) {
			arr[queueFirst][queueSecond - 1] = 1;
			q.push(make_pair(queueFirst, queueSecond - 1));
			checkProceed = true;
		}
		if (queueFirst + 1 < n && arr[queueFirst + 1][queueSecond] == 0) {
			arr[queueFirst + 1][queueSecond] = 1;
			q.push(make_pair(queueFirst + 1, queueSecond));
			checkProceed = true;
		}
		if (queueSecond + 1 < m && arr[queueFirst][queueSecond + 1] == 0) {
			arr[queueFirst][queueSecond + 1] = 1;
			q.push(make_pair(queueFirst, queueSecond + 1));
			checkProceed = true;
		}
	}

	if (!checkProceed) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 0) {
					checkZero = true;
				}
			}
		}
		if (!checkZero) {
			printf("%d\n", days);
		}
		else {
			printf("-1\n");
		}
	}
	else {
		bfs(days + 1);
	}
}

int main() {
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
	
	bfs(0);
	
	return 0;
}