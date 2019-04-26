//solved by SANGYUNLEE

#include<stdio.h>
#include<queue>

using namespace std;

int arr[100][100] = {};
int peopleNum, calculFirst, calculSecond, relationNum;


void bfs() {
	for (int i = 0; i < peopleNum; i++) {
		for (int j = 0; j < peopleNum; j++) {
			for (int k = 0; k < peopleNum; k++) {
				if (arr[j][k] > arr[j][i] + arr[i][k]) {
					arr[j][k] = arr[j][i] + arr[i][k];
					arr[k][j] = arr[j][k];
				}
			}
		}
	}
}

int main() {
	scanf("%d", &peopleNum);
	scanf("%d %d", &calculFirst, &calculSecond);
	scanf("%d", &relationNum);
	int tempFirst, tempSecond;
	for (int i = 0; i < relationNum; i++) {
		scanf("%d %d", &tempFirst, &tempSecond);
		arr[tempFirst - 1][tempSecond - 1] = 1;
		arr[tempSecond - 1][tempFirst - 1] = 1;
	}

	for (int i = 0; i < peopleNum; i++) {
		for (int j = 0; j < peopleNum; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 999;
			}
		}
	}

	bfs();
	if (arr[calculFirst - 1][calculSecond - 1] < 999) {
		printf("%d\n", arr[calculFirst - 1][calculSecond - 1]);
	}
	else {
		printf("-1\n");	
	}
}