//Solved By SANGYUNLEE

#include<stdio.h>
#include<deque>

using namespace std;

int testCases;
char ac[100010] = {};

int main() {
	scanf("%d", &testCases);
	while (testCases--) {
		int arrNum;
		int numDec;
		char trashValue;
		bool frontCheck = true;
		bool errorCheck = false;
		deque<int> d;

		scanf("%s \n%d \n%c", ac, &arrNum, &trashValue);
		if (arrNum) {
			for (int i = 0; i < arrNum; i++) {
				scanf("%d%c", &numDec, &trashValue);
				d.push_back(numDec);
			}
		}
		else {
			scanf("%c", &trashValue);
		}

		char curChar;
		for (int i = 0; ac[i] != '\0'; i++) {
			curChar = ac[i];
			if (curChar == 'R') {
				frontCheck = !frontCheck;
			}
			else if (curChar == 'D') {
				if (d.empty()) {
					errorCheck = true;
					break;
				}
				else if (frontCheck) {
					d.pop_front();
				}
				else {
					d.pop_back();
				}
			}
		}
		int temp;
		if (errorCheck) {
			printf("error\n");
		}
		else if (frontCheck) {
			printf("[");
			while (!d.empty()) {
				temp = d.front();
				d.pop_front();
				printf("%d", temp);
				if (!d.empty()) {
					printf(",");
				}
			}
			printf("]\n");
		}
		else {
			printf("[");
			while (!d.empty()) {
				temp = d.back();
				d.pop_back();
				printf("%d", temp);
				if (!d.empty()) {
					printf(",");
				}
			}
			printf("]\n");
		}
	}

}