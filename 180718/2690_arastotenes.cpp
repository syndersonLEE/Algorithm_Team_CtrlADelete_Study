//Solved By SANGYUNLEE

#include<stdio.h>

bool visited[1001];
int n, k, stateNum;

int main() {
	scanf("%d %d", &n, &k);
	stateNum = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 1;i*j<=n; j++) {
			if (!visited[i*j]) {
				visited[i*j] = true;
				stateNum++;
			}
			if (stateNum == k) {
				printf("%d\n", i*j);
				break;
			}
		}
		if (stateNum == k) {
			break;
		}
	}
}