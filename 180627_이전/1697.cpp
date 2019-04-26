//���ٲ��� BaekJoon Solved by �̻���

#include<cstdio>
#include<queue>

using namespace std;

int n, k, visited[100001];
queue<int> q;

int hide_seek() { //bfs �Լ� ����
	if (n == k)
		return 0;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int temp = q.front();
		q.pop();//q�� �Ǿհ� ������
		if (temp == k) {
			return visited[temp] - 1;
		}

		if (temp - 1 >= 0 && visited[temp-1] == false) { //-1Ȯ��
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