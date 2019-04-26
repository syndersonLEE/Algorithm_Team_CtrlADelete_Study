//Solved By SANGYUNLEE

#include<stdio.h>
#include<algorithm>

using namespace std;

int region, maxBud = 0;
long long budget, totBud = 0;
int reqBud[100001];

void allocBud();

int main() {
	scanf("%d", &region);
	for (int i = 0; i < region; i++) {
		scanf("%d", &reqBud[i]);
		maxBud = max(maxBud, reqBud[i]);
		totBud += reqBud[i];
	}
	scanf("%lld", &budget);

	if (totBud <= budget) {
		printf("%d\n", maxBud);
	}
	else {
		allocBud();
	}
}

void allocBud() {
	int left, right, mid;
	long long totValBot, totValTop;
	left = 0; right = maxBud;

	while (left <= right) {
		mid = (left + right) / 2;
		totValBot = 0;
		totValTop = 0;
		
		for (int i = 0; i < region; i++) {
			if (reqBud[i] > mid) {
				totValBot += mid;
			}
			else {
				totValBot += reqBud[i];
			}

			if (reqBud[i] > (mid + 1)) {
				totValTop += (mid + 1);
			}
			else {
				totValTop += reqBud[i];
			}
		}
		
		if (totValBot <= budget &&  budget < totValTop) {
			break;
		}
		else if (budget < totValBot) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d\n", mid);
}
