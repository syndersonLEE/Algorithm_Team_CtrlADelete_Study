//연속합 BaekJoon Solved by 이상윤

#include<cstdio>
#include<algorithm>

using namespace std;

int num[100001];
long long box[100001];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		box[i] = num[i];
	}

	for (int i = 1; i < n; i++) {
		box[i] = max(box[i], box[i - 1] + num[i]);
	}

	long long ans = box[0];
	for (int i = 1; i < n; i++) {
		ans = max(ans, box[i]);
	}
	printf("%lld\n", ans);

}