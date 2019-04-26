#include<iostream>
#include<cmath>

using namespace std;

int N, R, C, ans = 0;

void findZ(int size) {
	if(size != 1) {
		int blockSize = (size / 2)*(size / 2);
		while (R - size >= 0) {
			R -= size;
		}
		while (C - size >= 0) {
			C -= size;
		}
		if (R >= size / 2) {
			if (C >= size / 2) {
				ans += blockSize * 3;
			}
			else {
				ans += blockSize * 2;
			}
		}
		else {
			if (C >= size / 2) {
				ans += blockSize;
			}
		}
		findZ(size / 2);
	}
}

int main() {
	cin >> N >> R >> C;
	int realN = pow(2, N);
	findZ(realN);
	cout << ans << "\n";
}