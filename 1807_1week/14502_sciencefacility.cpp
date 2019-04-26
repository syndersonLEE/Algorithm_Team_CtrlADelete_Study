#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int m, n;
int maxSafe = 0;
int arr[8][8];
int tempArr[8][8];

vector<int> freeBlock;
queue<pair<int, int>> q;

void copyArr();
void setWall(int);
void bfs(int, int);

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	copyArr();
	setWall(0);
	printf("%d\n", maxSafe);
}

void copyArr() {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			tempArr[i][j] = arr[i][j];
		}
	}
}

void setWall(int wallCount) {
	if (wallCount == 3) {
		int safeArea = 0;
		copyArr();
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (tempArr[i][j] == 2) {
					bfs(i, j);
				}
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (tempArr[i][j] == 0) {
					safeArea++;
				}
			}
		}
		maxSafe = max(safeArea, maxSafe);
	}
	else {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 0) {

					arr[i][j] = 1;
					setWall(wallCount + 1);
					arr[i][j] = 0;
				}
			}
		}
	}
}

void bfs(int i,int j) {
	q.push(make_pair(i,j));
	while (!q.empty()) {
		tempArr[q.front().first][q.front().second] = 3;
		if (i - 1 >= 0 && tempArr[q.front().first - 1][q.front().second] == 0) {
			q.push(make_pair(i - 1, j));
		}
		if (j - 1 >= 0 && tempArr[q.front().first][q.front().second - 1] == 0) {
			q.push(make_pair(i, j -1));
		}
		if (i + 1 < m && tempArr[q.front().first + 1][q.front().second] == 0) {
			q.push(make_pair(i + 1, j));
		}
		if (j + 1 < n && tempArr[q.front().first][q.front().second + 1] == 0) {
			q.push(make_pair(i, j + 1));
		}
	}
}