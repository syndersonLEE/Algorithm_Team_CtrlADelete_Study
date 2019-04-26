/*Question 1260 DFS ¿Í BFS in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_NUM 1002
using namespace std;
vector<vector<bool>> box(MAX_NUM + 1, vector<bool>(MAX_NUM + 1, false));
vector<bool> check(MAX_NUM + 1,false);

void dfs(int v, int n) {
	check[v] = true;
	for (int i = 1;i <= n;i++) {
		if (!check[i]&&box[v][i]) {
			cout << i << " ";
			dfs(i, n);
		}
	}
}

int main() {
	int n, m, v;
	cin >> n >> m >> v;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		box[a][b] = true;
		box[b][a] = true;
	}
	cout << v << " ";
	dfs(v,n);
	cout << endl;

	fill(check.begin(), check.end(), false);
	bfs(v, n);
	cout << endl;
	return 0;
}