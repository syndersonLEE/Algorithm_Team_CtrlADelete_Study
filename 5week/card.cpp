/*Question 11652 Ä«µå	in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	long long k;
	cin >> n;
	long long *box = new long long[n];
	for (int i = 0;i < n;i++)
		cin >> box[i];
	sort(box, box + n);
	int b = 1;
	m = 0;
	k = box[0];
	for (int i = 1;i < n;i++) {
		if (box[i - 1] != box[i] || i == n - 1) {
			if (box[i - 1] == box[i])
				b++;
			if (b > m) {
				m = b;
				k = box[i - 1];
			}
			b = 1;
		}
		else
			b++;
	}
	cout << k << "\n";
	return 0;
}