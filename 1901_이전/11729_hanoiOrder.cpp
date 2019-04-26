#include<iostream>
#include<cmath>

using namespace std;

int N,K = 0;
int arr[2000000][2];

void hanoiOrder(int from,int to, int n) {
	if (n == 1) {
		arr[K][0] = from;
		arr[K++][1] = to;
	}
	else {
		hanoiOrder(from, 6 - from - to, n - 1);
		arr[K][0] = from;
		arr[K++][1] = to;
		hanoiOrder(6 - from - to, to, n - 1);
	}
}

int main() {
	ios::sync_with_stdio;
	cin >> N;
	hanoiOrder(1, 3, N);
	cout << K << "\n";
	for (int i = 0; i < K; i++) {
		cout << arr[i][0] << " " << arr[i][1] << "\n";
	}
}