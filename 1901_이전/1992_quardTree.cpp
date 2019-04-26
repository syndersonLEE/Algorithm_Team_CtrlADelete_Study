#include<iostream>

using namespace std;

int quadSize;
int arr[64][64];
int arrSum[64][64];

void quadTree(int row, int col, int size) {
	if (size == 1) {
		cout << arr[row][col];
	}
	else {
		int colSum = 0;
		for (int i = 0; i < size; i++) {
			colSum += (arr[row + i][col] + arrSum[row + i][col + size - 1] - arrSum[row + i][col]);
		}

		if (colSum == size * size) {
			cout << 1;
		}
		else if (colSum == 0) {
			cout << 0;
		}
		else {
			cout << "(";
			quadTree(row, col, size / 2);
			quadTree(row, col + size / 2, size / 2);
			quadTree(row + size / 2, col, size / 2);
			quadTree(row + size / 2, col + size / 2, size / 2);
			cout << ")";
		}
	}
}

int main() {
	ios::sync_with_stdio;
	cin >> quadSize;

	for (int i = 0; i < quadSize; i++) {
		char temp;
		int colSum = 0;
		for(int j = 0; j < quadSize; j++) {
			cin >> temp;
			colSum += (temp - '0');
			arr[i][j] = temp - '0';
			arrSum[i][j] = colSum;
		}
	}

	quadTree(0, 0, quadSize);
	cout << "\n";
}