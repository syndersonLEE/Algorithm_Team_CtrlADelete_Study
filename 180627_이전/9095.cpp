//이친수 BaekJoon Solved by 이상윤

#include<cstdio>
#include<algorithm>

using namespace std;

long long arr[92][2];

int main() {
	int n;
	scanf("%d", &n);
	arr[0][0] = 0; arr[0][1] = 1;
	arr[1][0] = 1; arr[1][1] = 0;
	for (int i = 2; i < n; i++) {
		arr[i][0] = arr[i - 1][0] + arr[i - 1][1];
		arr[i][1] = arr[i - 1][0];
	}
	printf("%lld\n", (arr[n - 1][0] + arr[n - 1][1]));
	return 0;
}