#include<iostream>
#define MAX 1985938245

using namespace std;

int testCase, n;
long long arr[140] = { 1, 1, 2, 4 };

int main() {
	for (int i = 4; i <= 67; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3] + arr[i - 4];
	}
	cin >> testCase;
	while (testCase--) {
		cin >> n;
		cout << arr[n] << "\n";
	}
}