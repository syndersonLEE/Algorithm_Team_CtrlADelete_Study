#include<iostream>
#include<algorithm>

using namespace std;

char arr[100];
long long x, y;
char blank;
int limit[101];

int main() {
	while (1) {
		cin.getline(arr, 100);
		if (arr[0] == '\0') {
			break;
		}
		int iterArr = 0;
		x = 0; y = 0;
		while (arr[iterArr] != 32) {
			x *= 10;
			x += (arr[iterArr]-48);
			iterArr++;
		}
		iterArr++;
		while (arr[iterArr] != '\0') {
			y *= 10;
			y += (arr[iterArr] - 48);
			iterArr++;
		}
		
		long long left, right, mid, revisePer, ans = 2e9;
		long long oriPer = (y * 100) / x;
		left = 0; right = 2e9;
		while (left <= right) {
			if (oriPer >= 99) {
				ans = -1;
				break;
			}
			mid = (left + right) / 2;
			revisePer = ((y + mid) * 100) / (x + mid);
			
			if (oriPer < revisePer) {
				right = mid - 1;
				ans = mid;
			}
			else {
				left = mid + 1;
			}
		}
		printf("%lld\n", ans);
	}
}