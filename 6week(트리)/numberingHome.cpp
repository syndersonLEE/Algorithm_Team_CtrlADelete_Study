/*Question 2667 단지 번호 붙이기 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<cstdio>
#include<algorithm>
#include<vector>
#define MAX_NUM 1000
using namespace std;

vector<vector<int>> box(MAX_NUM, vector<int>(MAX_NUM, 0));
vector<vector<bool>> visit(MAX_NUM, vector<bool>(MAX_NUM, false));
int ans[MAX_NUM];
int dfs(int x, int y) {
	visit[x][y] = true;
	int temp = 1;
	if ((!box[x + 1][y] || visit[x + 1][y]) && (!box[x][y + 1] || visit[x][y + 1]) &&
		(!box[x-1][y] || visit[x-1][y])&& (!box[x][y -1] || visit[x][y -1]))
		return 1;
	else {
		if (box[x + 1][y] && !visit[x + 1][y])
			temp += dfs(x + 1, y);
		if (box[x][y+1] && !visit[x][y+1])
			temp += dfs(x, y+1);
		if (box[x][y - 1] && !visit[x][y - 1])
			temp += dfs(x, y - 1);
		if (box[x-1][y] && !visit[x-1][y])
			temp += dfs(x-1, y);
		return temp;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			scanf("%1d", &box[i][j]);
		}
	}
	int ans_num = 0;
	for(int i=1;i<=n;i++)
		for (int j = 1;j <= n;j++) {
			if (box[i][j] && !visit[i][j]) {
				ans[ans_num] = dfs(i, j);
				ans_num++;
			}
		}
	sort(ans,ans+ans_num);
	printf("%d\n", ans_num);
	for (int i = 0;i < ans_num;i++)
		printf("%d\n", ans[i]);
	
}