//숨바꼭질 BaekJoon Solved by 이상윤

#include<cstdio>
#include<queue>

using namespace std;

int n, k, visited[100001];
queue<int> q;

int hide_seek() { //bfs 함수 시작
	if (n == k)
		return 0;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();//q의 맨앞값 꺼내기
		if (temp == k) {
			return visited[temp] - 1;
		}

		if (temp - 1 >= 0 && visited[temp-1] == false) { //-1확인
			visited[temp - 1] = visited[temp] + 1;
			q.push(temp - 1);
		}
		if (temp + 1 < 100001 && visited[temp + 1] == false) {
			visited[temp + 1] = visited[temp] + 1;
			q.push(temp + 1);
		}
		if (temp * 2 < 100001 && visited[temp*2] == false) {
			visited[temp * 2] = visited[temp] + 1;
			q.push(temp * 2);
		}
	}
}

int main() {
	scanf("%d %d", &n, &k);
	printf("%d\n",hide_seek());
	return 0;
}