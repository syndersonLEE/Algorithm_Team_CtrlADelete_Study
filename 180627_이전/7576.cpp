//토마토 BaekJoon Solved by 이상윤

#include<cstdio>
#include<queue>

using namespace std;

int arr[1001][1001];
int visited[1001][1001];
queue<pair<int,int>> q;

int tomato(int w, int h) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if(x>1000)
	}
}


int main() {
	int w, h;
	scanf("%d %d", &w, &h);
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			scanf("%d", &arr[i][j]);
			if (arr[i][j] == 1) {
				q.push(make_pair(w, h));
			}
		}
	}
	printf("%d\n",tomato(w, h));
}