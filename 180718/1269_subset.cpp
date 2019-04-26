#include <stdio.h>
#include <queue>

using namespace std;

int numA, numB;
priority_queue<int, vector<int>, greater<int>> aSet, bSet;
void compAB();

int main() {
	scanf("%d %d", &numA, &numB);
	for (int i = 0; i < numA; i++) {
		int temp;
		scanf("%d", &temp);
		aSet.push(temp);
	}
	for (int i = 0; i < numB; i++) {
		int temp;
		scanf("%d", &temp);
		bSet.push(temp);
	}

	compAB();
}

void compAB() {
	int ans = 0;
	while (!aSet.empty() && !bSet.empty()) {
		if (aSet.top() > bSet.top()) {
			bSet.pop();
			ans++;
		}
		else if (aSet.top() < bSet.top()) {
			aSet.pop();
			ans++;
		}
		else {
			aSet.pop();
			bSet.pop();
		}
	}
	ans += (aSet.size() + bSet.size());
	printf("%d\n", ans);
}