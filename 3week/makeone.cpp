#include<iostream>
#include<algorithm>
#define MAX_NUM 1000001
using namespace std;
int arr[MAX_NUM]; // try number
int makeone(int x) {
	if (x == 1)
		return 0;
	else if (arr[x] > 0)
		return arr[x];
	else {
		arr[x] = makeone(x-1) + 1;
		if (!(x % 2))
			arr[x] = min(arr[x], makeone(x / 2) + 1);
		if (!(x % 3))
			arr[x] = min(arr[x], makeone(x / 3) + 1);
		return arr[x];
	}
}

int main() {
	int a;
	cin >> a;
	fill(arr, arr + a + 1, -1);
	cout << makeone(a) << endl;
	return 0;
}