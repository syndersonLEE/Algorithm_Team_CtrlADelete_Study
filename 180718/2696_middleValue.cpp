//Solved By SANGYUNLEE

#include<stdio.h>
#include<queue>
#include<algorithm>

using namespace std;

int testCases;
int numLength;
int midNum;
int checkWay;

priority_queue<int> smallQueue;
priority_queue<int,vector<int>,greater<int>> bigQueue;

int main() {
	scanf("%d", &testCases);
	while (testCases--) {
		scanf("%d", &numLength);
		printf("%d\n", (numLength + 1) / 2);
		while (!bigQueue.empty()) {
			bigQueue.pop();
		}
		while (!smallQueue.empty()) {
			smallQueue.pop();
		}

		checkWay = 0;
		for (int i = 0; i < numLength; i++) {
			int temp;
			scanf("%d", &temp);
			if (i == 0) {
				midNum = temp;
				printf("%d ", midNum);
			}
			else {
				if (midNum >= temp) {
					smallQueue.push(temp);
					checkWay--;
				}
				else {
					bigQueue.push(temp);
					checkWay++;
				}

				if (i % 2 == 0) {
					if (checkWay == 0) {
						printf("%d ", midNum);
					}
					else if (checkWay > 0) {
						smallQueue.push(midNum);
						midNum = bigQueue.top();
						bigQueue.pop();
						printf("%d ", midNum);
					}
					else {
						bigQueue.push(midNum);
						midNum = smallQueue.top();
						smallQueue.pop();
						printf("%d ", midNum);
					}
					checkWay = 0;
				}
			}
		}
		printf("\n");
	}
}