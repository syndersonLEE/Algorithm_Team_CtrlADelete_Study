#include<iostream>
#include<string.h>

using namespace std;

int testCase, n, sum;
bool room[101];

int main() {
	cin >> testCase;
	while (testCase--) {
		sum = 0;
		memset(room, false, sizeof(room));
		cin >> n;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j * i <= n; j++) {
				room[j * i] = !(room[j * i]);
			}
		}

		for (int i = 1; i <= n; i++) {
			if (room[i])
				sum++;
		}
		cout << sum << "\n";
	}
}