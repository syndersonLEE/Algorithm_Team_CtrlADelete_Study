#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

priority_queue <pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>>> usedRoom;
pair<int, int> classT[200001];

int numClass, temp1, temp2, ans;

int main() {
	scanf("%d", &numClass);
	for (int i = 0; i < numClass; i++) {
		scanf("%d %d", &temp1, &temp2);
		classT[i] = make_pair(temp1, temp2);
	}
	sort(classT, classT + numClass);

	for (int i = 0; i < numClass; i++) {
		if (usedRoom.empty()) {
			usedRoom.push(make_pair(classT[i].second, classT[i].first));
		}
		else if (usedRoom.top().first <= classT[i].first) {
			usedRoom.push(make_pair(classT[i].second, classT[i].first));
			usedRoom.pop();
		}
		else {
			usedRoom.push(make_pair(classT[i].second, classT[i].first));
		}
	}

	ans = usedRoom.size();
	printf("%d\n", ans);
}