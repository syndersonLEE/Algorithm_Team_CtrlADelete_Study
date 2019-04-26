//포도주 시식 BaekJoon Solved by 이상윤

#include<cstdio>
#include<algorithm>

using namespace std;

long long arr[10002][3];

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		if (i == 1) {
			arr[i][0] = 0;
			arr[i][1] = temp;
			arr[i][2] = temp;
		}
		else {
			arr[i][0] = max({ arr[i - 1][0],arr[i - 1][1], arr[i - 1][2] });
			arr[i][1] = arr[i-1][0] + temp;
			arr[i][2] = arr[i-1][1] + temp;
		}
	}
	long long ans = max({ arr[n][0], arr[n][1],arr[n][2] });
	printf("%lld\n", ans);
}
