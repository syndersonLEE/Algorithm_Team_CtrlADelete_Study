//Solved By SANGYUNLEE
#include<stdio.h>
#include<stdlib.h>
#include<queue>

using namespace std;

bool arr[1001][1001] = {};

void bfs(int vertex, int startNum) {
	queue<int> q; 
	bool visitedDfs[1001] = {};
	int startVer;
	q.push(startNum);
	for (int i = 1; i <= vertex; i++) {
		startVer = q.front();
		visitedDfs[startVer] = true;
		printf("%d ", startVer);
		q.pop();

		for (int j = 1; j <= vertex; j++) {
			if (i == vertex) {
				break;
			}
			if (arr[startVer][j] == true && !visitedDfs[j]) {
				visitedDfs[j] = true;
				q.push(j);
			}
		}

	}
	printf("\n");
}

void dfs(int vertex, int startNum) {
	bool visitedBfs[1001] = {};
	int startVer = startNum;
	for (int i = 1; i <= vertex; i++) {
		visitedBfs[startVer] = true;
		printf("%d ", startVer);

		for (int j = 1; j <= vertex; j++) {
			if (i == vertex) {
				break;
			}

			if (arr[startVer][j] == true && !visitedBfs[j]) {
				startVer = j;
				break;
			}
		}
	}
	printf("\n");
}

int main() {
	int vertex;
	int ray;
	int startNum;
	scanf("%d %d %d", &vertex, &ray, &startNum);
	
	for (int i = 0; i < ray; i++) {
		int ver1, ver2;
		scanf("%d %d", &ver1, &ver2);
		arr[ver1][ver2] = true;
		arr[ver2][ver1] = true;
	}
	dfs(vertex, startNum);
	bfs(vertex, startNum);
}