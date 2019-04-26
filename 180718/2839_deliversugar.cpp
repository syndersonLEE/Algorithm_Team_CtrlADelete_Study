//Solved By SAGNYUNLEE

#include<stdio.h>

using namespace std;

int n;
int numFive;

int main() {
	scanf("%d", &n);
	for (int i = 1;; i++) {
		if ((i + 1) * 5 > n) {
			numFive = i;
			break;
		}
	}

	while (numFive >= 0) {
		if ((n - numFive * 5) % 3 == 0) {
			break;
		}
		else {
			numFive--;
		}
	}

	if (numFive >= 0) {
		int total = numFive + ((n - numFive * 5) / 3);
		printf("%d\n", total);
	}
	else {
		printf("-1\n");
	}
}