//Solved By SANGYUNLEE

#include<stdio.h>
#include<queue>
#include<math.h>

using namespace std;

int evalCases;
priority_queue<int> minusQueue;
priority_queue<int, vector<int>, greater<int>> plusQueue;

int main() {
	scanf("%d", &evalCases);
	while (evalCases--) {
		int temp;
		scanf("%d", &temp);
		if (temp > 0) {
			plusQueue.push(temp);
		}
		else if (temp < 0) {
			minusQueue.push(temp);
		}
		else {
			if (minusQueue.empty() || plusQueue.empty()) {
				if (minusQueue.empty() && plusQueue.empty()) {
					printf("0\n");
				}
				else if (plusQueue.empty()) {
					printf("%d\n", minusQueue.top());
					minusQueue.pop();
				}
				else {
					printf("%d\n", plusQueue.top());
					plusQueue.pop();
				}
			}
			else if (abs(minusQueue.top()) <= abs(plusQueue.top())) {
				printf("%d\n", minusQueue.top());
				minusQueue.pop();
			}
			else {
				printf("%d\n", plusQueue.top());
				plusQueue.pop();
			}
		}
	}
	
}
