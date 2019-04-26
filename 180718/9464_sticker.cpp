//solved by SANGYUNLEE

#include<stdio.h>
#include<algorithm>

using namespace std;


int cost[100000][2] = {};
int point[100000][3] = {};

int main() {
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		int wid;

		scanf("%d", &wid);
		
		for (int i = 0; i < wid; i++) {
			for (int j = 0; j < 3; j++) {
				point[i][j] = 0;
			}
		}

		for (int i = 0; i < wid; i++) {
			scanf("%d", &cost[i][0]);
		}
		for (int i = 0; i < wid; i++) {
			scanf("%d", &cost[i][1]);
		}

		point[0][0] = 0;
		point[0][1] = cost[0][0];
		point[0][2] = cost[0][1];


		for (int i = 1; i < wid; i++) {
			point[i][0] = max({point[i - 1][0], point[i - 1][1], point[i - 1][2]});
			point[i][1] = max(point[i - 1][0], point[i - 1][2]) + cost[i][0];
			point[i][2] = max(point[i - 1][0], point[i - 1][1]) + cost[i][1];
		}
		int ans = max({ point[wid - 1][0], point[wid - 1][1], point[wid - 1][2] });

		printf("%d\n", ans);
	}
	
}