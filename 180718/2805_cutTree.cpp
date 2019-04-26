#include<iostream>
#include<algorithm>

using namespace std;


int woodNum, needLen;
long long woodLen[1000001];
long long maxLen = 0;
void checkWood();

int main() {
	cin >> woodNum >> needLen;
	for (int i = 0; i < woodNum; i++) {
		cin >> woodLen[i];
		maxLen = max(woodLen[i], maxLen);
	}
	checkWood();
}

void checkWood() {
	long long left = 0, right = maxLen;
	long long totalWoodTop, totalWoodBot, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		totalWoodTop = 0;
		totalWoodBot = 0;
		for (int i = 0; i < woodNum; i++) {
			if ((woodLen[i] - mid) > 0) {
				totalWoodBot += (woodLen[i] - mid); //¾Æ·¡ÂÊ ´õ ±è
			}
			if ((woodLen[i] - (mid + 1)) > 0) {
				totalWoodTop += (woodLen[i] - (mid + 1)); // À§ÂÊ ´õ ÂªÀ½
			}
		}

		if (totalWoodTop < needLen && needLen <= totalWoodBot) {
			break;
		}
		else if (totalWoodTop >= needLen)
			left = mid + 1;
		else {
			right = mid - 1;
		}
	}
	cout << mid << "\n";
}