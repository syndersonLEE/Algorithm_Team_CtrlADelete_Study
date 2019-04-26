//¼ıÀÚ»ï°¢Çü BaekJoon Solved by ÀÌ»óÀ±

#include<cstdio>
#include<algorithm>

using namespace std;

long long arr[502][502];
int num[502];

int main() {
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) { 
			scanf("%d", &num[j]);
			if (i == 1)  
				arr[i][j] = num[1]; 
			else if (j == 1) 
				arr[i][j] = arr[i - 1][j] + num[j];
			else if (j == i) 
				arr[i][j] = arr[i - 1][j - 1] + num[j];
			else 
				arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + num[j];

			if (i == n) 
				ans = max(ans, arr[i][j]);
		}
	}

	printf("%lld\n",ans);
}