/*Question 11724 연결 요소의 개수 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX_NUM 1002
using namespace std;

vector<vector<bool>> box(MAX_NUM + 1, vector<bool>(MAX_NUM + 1, false));
vector<bool> check(MAX_NUM + 1, false);

void dfs(int v, int n) {
	check[v] = true;
	for (int i = 1;i <= n;i++) {
		if (!check[i] && box[v][i]) {
			dfs(i, n);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		box[a][b] = true;
		box[b][a] = true;
	}
	int comp_num = 0;
	for (int i = 1;i <= n;i++) {
		if (check[i] == false) {
			dfs(i, n);
			comp_num++;
		}
	}
	cout << comp_num << endl;
	return 0;
}