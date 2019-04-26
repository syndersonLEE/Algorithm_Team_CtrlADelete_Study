#include<iostream>
#include<algorithm>

using namespace std;

int n, m;
int sptNum[301][301] = { 0 };

int cutCho(int wid, int hei) {
	if (sptNum[wid][hei] != 0) {
		return sptNum[wid][hei];
	}
	else if (wid == 1 && hei == 1) {
		return 0;
	}
	else if ((wid == 1 && hei == 2) && (wid == 2 && hei == 1)) {
		return 1;
	}
	else {
		if (wid == 1) {
			sptNum[1][hei] = hei - 1;
			return (hei - 1);
		}
		else if (hei == 1) {
			sptNum[1][hei] = wid - 1;
			return (wid - 1);
		}
		else {
			int temp = 10000000;
			for (int i = 1; i <= (hei / 2); i++) {
				temp = min(temp, cutCho(wid, hei - i) + cutCho(wid, i) + 1);
			}
			for (int i = 1; i <= (wid / 2); i++) {
				temp = min(temp, cutCho(wid - i, hei) + cutCho(i, hei) + 1);
			}
			sptNum[wid][hei] = temp;
			return sptNum[wid][hei];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	cout << cutCho(n, m) << "\n";
	
}