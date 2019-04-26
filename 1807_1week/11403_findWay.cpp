//solved by SANGYUNLEE

#include<stdio.h>
#include<queue>

using namespace std;

int arr[100][100];
int visited[100][100];
int length;


void ployd() {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			for (int k = 0; k < length; k++) {
				if (arr[j][k] == 0 && arr[j][i] == 1 && arr[i][k] == 1) {
					arr[j][k] = 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &length);
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	ployd();

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}