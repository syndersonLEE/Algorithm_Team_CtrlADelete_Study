#include<iostream>

using namespace std;

int N;
int arr[2200][2200];
int ans[3];

void tripleTree(int row, int col, int size) {
	if (size == 1) {
		ans[arr[row][col] + 1]++;
	}
	else {
		int standNum = arr[row][col];
		bool numMatch = true;
		for (int i = 0; i < size && numMatch; i++) {
			for (int j = 0; j < size && numMatch; j++) {
				if (standNum != arr[row + i][col + j]) {
					numMatch = false;
				}
			}
		}

		if (numMatch) {
			ans[standNum + 1]++;
		}
		else {
			int nextLevel = size / 3;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					tripleTree(row + nextLevel*i, col + nextLevel*j, nextLevel);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	tripleTree(0, 0, N);

	for (int i = 0; i < 3; i++) {
		cout << ans[i] << "\n";
	}
}