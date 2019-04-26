//Solved By SANGYUN LEE
#include<stdio.h>
#include<stdlib.h>

using namespace std;


int main() {
	int testCases;
	scanf("%d", &testCases);
	while (testCases--) {
		int fibCount;
		int fibNum[41][2] = {};
		scanf("%d", &fibCount);
		fibNum[0][0] = 1;
		fibNum[0][1] = 0;
		fibNum[1][0] = 0;
		fibNum[1][1] = 1;
		for (int i = 2; i <= fibCount; i++) {
			fibNum[i][0] = fibNum[i - 1][0] + fibNum[i - 2][0];
			fibNum[i][1] = fibNum[i - 1][1] + fibNum[i - 2][1];
		}
		printf("%d %d\n", fibNum[fibCount][0], fibNum[fibCount][1]);
	}
}