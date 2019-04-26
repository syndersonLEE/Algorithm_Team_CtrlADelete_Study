/*Question 2178 ¹Ì·Î Å½»ö in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX_NUM 102
using namespace std;
int box[MAX_NUM][MAX_NUM];
int cnt[MAX_NUM][MAX_NUM];

void dfs(int x, int y) {
	for(int i=-1;i<=1;i++)
		for (int j = -1;j <= 1;j++) {
			if ((!i || !j) && box[x + i][y + j]) {
				if (!cnt[x + i][y + j]) {
					cnt[x + i][y + j] = cnt[x][y] + 1;
					dfs(x + i, y + j);
				}
				else if (cnt[x][y] + 1 < cnt[x + i][y + j]) {
					cnt[x + i][y + j] = cnt[x][y] + 1;
					dfs(x + i, y + j);
				}
			}
		}
}
int main() {
	int w, h;
	scanf("%d %d",&w,&h);
	for (int i = 1;i <= w;i++) {
		memset(box[i], 0, sizeof(box[i]));
		memset(cnt[i], 0, sizeof(box[i]));
		for (int j = 1;j <= h;j++)
			scanf("%1d", &box[i][j]);
	}
	cnt[1][1] = 1;
	dfs(1, 1);
	printf("%d\n", cnt[w][h]);
}