#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

bool arr[101][101] = {}; //0)empty&not visit 1)fill 2)empty&visit
int areaSize[10001];
int m, n, k;
int areaCount = 0;


void dfs(int wid, int hei) {
	arr[wid][hei] = 2;
	areaSize[areaCount]++;
	if (wid + 1 < m&&arr[wid + 1][hei] == 0) {
		dfs(wid + 1, hei);
	}
	if (wid - 1 >= 0&&arr[wid - 1][hei] == 0) {
		dfs(wid - 1, hei);
	}
	if (hei + 1 < n&&arr[wid][hei + 1] == 0) {
		dfs(wid, hei + 1);
	}
	if (hei - 1 >= 0&&arr[wid][hei - 1] == 0) {
		dfs(wid, hei - 1);
	}
	
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int temp1, temp2, temp3, temp4;
		scanf("%d %d %d %d", &temp1, &temp2, &temp3, &temp4);
		for (int x = temp1; x < temp3; x++) {
			for (int y = temp2; y < temp4; y++) {
				arr[x][y] = 1;
			}
		}
	}

	for (int x = 0; x < m; x++) {
		for (int y = 0; y < n; y++) {
			if (arr[x][y] == 0) {
				dfs(x, y);
				areaCount++;
			}
		}
	}

	sort(areaSize, areaSize + areaCount);
	printf("%d\n", areaCount);
	for (int i = 0; i < areaCount; i++) {
		printf("%d ",areaSize[i]);
	}
	printf("\n");
}