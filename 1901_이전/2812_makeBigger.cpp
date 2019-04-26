#include<iostream>

using namespace std;

int N, K, exMaxIter = 0;
long long ans = 0;
char numCont[500001];

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> numCont[i];
	}

	for (int i = N - K; i > 0; i--) {
		ans *= 10;
		int maxNum = -1;
		int maxIter;
		for (int j = exMaxIter; j <= N - i; j++) {
			if (maxNum < numCont[j] - '0') {
				maxNum = numCont[j] - '0';
				maxIter = j;
				if (maxNum == 9)
					break;
			}
		}
		cout << maxNum;
		exMaxIter = maxIter + 1;
	}
	
	cout << "\n";
}