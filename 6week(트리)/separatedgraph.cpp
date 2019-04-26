/*Question 1260 DFS ¿Í BFS in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

bool bfs(int v, int n, vector<bool> check, vector<bool> color, vector<vector<bool>> box) {
	queue<int> order;
	if (!check[v]) {
		check[v] = true;
		color[v] = 1;
		order.push(v);
	}
	else
		return true;
	while (order.size()) {
		int x = order.front();
		order.pop();
		for (int i = 1;i <= n;i++) {
			if (check[i] && box[x][i] && (color[x] == color[i])) {
				return false;
			}
			if (!check[i] && box[x][i]) {
				order.push(i);
				check[i] = true;
				color[i] = !color[x];
			}
		}
	}
	return true;
}
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		int m, l;
		bool bip_check = true;
		scanf("%d %d", &m, &l);
		vector<vector<bool>> box(m+3);
		vector<bool> check(m+3, 0);
		vector<bool> color(m+3, 0);
		for (int i = 0;i < l;i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			box[a].push_back(b);
			box[b].push_back(a);
		}
		for (int i = 1;i <= m;i++) {
			if (!bfs(i, m, check, color, box)) {
				bip_check = false;
				break;
			}
		}
		if (bip_check)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}