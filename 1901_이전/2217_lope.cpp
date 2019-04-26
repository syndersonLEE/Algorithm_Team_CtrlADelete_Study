#include<iostream>
#include<queue>

using namespace std;

int N, maxNum = 0, temp;
priority_queue<int> pq;

int main() {
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		pq.push(temp);
	}

	for (int i = 1; i <= N; i++) {
		maxNum = max(maxNum, pq.top() * i);
		pq.pop();
	}

	printf("%d\n", maxNum);

	
}