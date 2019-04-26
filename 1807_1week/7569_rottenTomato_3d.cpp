//solved by SANGYUNLEE

#include<stdio.h>
#include<queue>

using namespace std;

queue<pair<int,pair<int,int>>> q;

int m, n, o;
int arr[100][100][100];

void bfs(int days) {
	int queueSize = q.size();
	bool checkProceed = false;
	bool checkZero = false;
	for (int i = 0; i < queueSize; i++) {
		int queueFirst = q.front().first;
		int queueSecond = q.front().second.first;
		int queueThird = q.front().second.second;
		q.pop();
		if (queueFirst - 1 >= 0 && arr[queueFirst - 1][queueSecond][queueThird] == 0) {
			arr[queueFirst - 1][queueSecond][queueThird] = 1;
			q.push(make_pair(queueFirst - 1, make_pair(queueSecond, queueThird)));
			checkProceed = true;
		}
		if (queueFirst + 1 < o && arr[queueFirst + 1][queueSecond][queueThird] == 0) {
			arr[queueFirst + 1][queueSecond][queueThird] = 1;
			q.push(make_pair(queueFirst + 1, make_pair(queueSecond, queueThird)));
			checkProceed = true;
		}
		if (queueSecond - 1 >= 0 && arr[queueFirst][queueSecond - 1][queueThird] == 0) {
			arr[queueFirst][queueSecond - 1][queueThird] = 1;
			q.push(make_pair(queueFirst, make_pair(queueSecond - 1,queueThird)));
			checkProceed = true;
		}
		if (queueSecond + 1 < n && arr[queueFirst][queueSecond + 1][queueThird] == 0) {
			arr[queueFirst][queueSecond + 1][queueThird] = 1;
			q.push(make_pair(queueFirst, make_pair(queueSecond + 1,queueThird)));
			checkProceed = true;
		}
		if (queueThird - 1 >= 0 && arr[queueFirst][queueSecond][queueThird - 1] == 0) {
			arr[queueFirst][queueSecond][queueThird - 1] = 1;
			q.push(make_pair(queueFirst, make_pair(queueSecond, queueThird - 1)));
			checkProceed = true;
		}
		if (queueThird + 1 < m && arr[queueFirst][queueSecond][queueThird + 1] == 0) {
			arr[queueFirst][queueSecond][queueThird + 1] = 1;
			q.push(make_pair(queueFirst, make_pair(queueSecond, queueThird + 1)));
			checkProceed = true;
		}
	}

	if (!checkProceed) {
		for (int i = 0; i < o; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					if (arr[i][j][k] == 0) {
						checkZero = true;
					}
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
	scanf("%d %d %d", &m, &n, &o);
	for (int i = 0; i < o; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				scanf("%d", &arr[i][j][k]);
				if (arr[i][j][k] == 1) {
					q.push(make_pair(i, make_pair(j, k)));
				}
			}
		}
	}

	bfs(0);

	return 0;
}