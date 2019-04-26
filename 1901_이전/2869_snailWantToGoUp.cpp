#include<iostream>

using namespace std;

int A, B, V, ans = 0;

int main() {
	ios::sync_with_stdio;
	cin >> A >> B >> V;
	int res = V - A;
	if (res % (A-B) == 0) {
		ans += (res / (A - B) + 1);
	}
	else {
		ans += (res / (A - B) + 2);
	}
	cout << ans << "\n";
}