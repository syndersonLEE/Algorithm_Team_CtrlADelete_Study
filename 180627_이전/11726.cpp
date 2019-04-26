//2xn 타일링 BaekJoon Solved by 이상윤

#include<cstdio>

using namespace std;

long long arr[1002];

int main() {
	int n;
	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 2;
	for (int i = 3; i <= n; i++) 
		arr[i] = (arr[i - 1] + arr[i - 2])%10007;
	
	printf("%lld\n", arr[n]);
}
