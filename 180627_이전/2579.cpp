//계단 오르기 BaekJoon Solved by 이상윤

#include<cstdio>
#include<algorithm>

using namespace std;

int box[10001][2];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		if (i == 0) { box[0][0] = temp; box[0][1] = 0; }
		else if (i == 1) { box[1][0] = temp; box[1][1] = box[0][0] + temp; }
		else {
			box[i][0] = max(box[i - 2][0], box[i - 2][1]) + temp;
			box[i][1] = box[i - 1][0] + temp;
		}
	}
	printf("%d\n", max(box[n - 1][0], box[n - 1][1]));
}