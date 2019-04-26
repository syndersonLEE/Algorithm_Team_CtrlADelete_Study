// Solved By SANGYUNLEE
#include<stdio.h>
#include<queue>

using namespace std;

int comNum, relationNum, maxCount = 0;
bool arr[10000][10000] = {};
int hackCount[10000] = {};
bool visited[10000];

queue<int> q;

void clearVisited() {
	for (int i = 0; i < comNum; i++) {
		visited[i] = false;
		maxCount = max(hackCount[i], maxCount);
	}
}

void bfs(int startPoint) {
	for (int i = 0; i < comNum; i++) {
		if (arr[startPoint][i] && !visited[i]) {

		}
	}
}

int main() {
	int tempFirst, tempSecond;
	scanf("%d %d", &comNum, &relationNum);
	for (int i = 0; i < relationNum; i++) {
		scanf("%d %d", &tempFirst, &tempSecond);
		arr[tempSecond - 1][tempFirst - 1] = true;
	}
	for (int i = 0; i < comNum; i++) {
		clearVisited();
		dfs(i);
	}
	for (int i = 0; i < comNum; i++) {
		if (maxCount == hackCount[i]) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");

}