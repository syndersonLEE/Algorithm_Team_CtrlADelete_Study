#include<iostream>

using namespace std;

int arr[502][502];
int M, N, ans = 0;

void findWay(int hei, int wid) {
	if (hei == M && wid == N) {
		ans++;
	}
	else {
		if (arr[hei + 1][wid] && arr[hei][wid] > arr[hei + 1][wid]) {
			findWay(hei + 1, wid);
		}
		if (arr[hei][wid + 1] && arr[hei][wid] > arr[hei][wid + 1]) {
			findWay(hei, wid + 1);
		}
		if (arr[hei][wid - 1] && arr[hei][wid] > arr[hei][wid - 1]) {
			findWay(hei, wid - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio;
	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	findWay(1, 1);

	cout << ans << "\n";
}