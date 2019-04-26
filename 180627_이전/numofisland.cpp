/*Question 2667 단지 번호 붙이기 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX_NUM 52
using namespace std;
int box[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = -1;i <= 1;i++) {
		for (int j = -1;j <= 1;j++) {
			if ((box[x + i][y + j]) && (!visited[x + i][y + j]))
				dfs(x + i, y + j);
		}
	}
}
int main() {
	while (1) {
		int w, h;
		cin >> w >> h;
		if (!w && !h)
			break;
		for (int i = 1;i <= h;i++) {
			memset(box[i], 0, sizeof(box[i]));
			memset(visited[i], false, sizeof(visited[i]));
			for (int j = 1;j <= w;j++) 
				cin>>box[i][j];
		}
		int ans = 0;
		for (int i = 1;i <= h;i++)
			for (int j = 1;j <= w;j++)
				if (box[i][j] && !visited[i][j]) {
					dfs(i, j);
					ans++;
				}
		cout<<ans<<"\n";
	}
	return 0;
}