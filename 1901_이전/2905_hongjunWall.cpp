#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int N, X, contNum, paintNum, restSpace;
int arr[1000001];
int minX[1000000];
multiset<int> minSet;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> X;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	
	minX[0] = 1000001;
	for (int i = 0; i < X; i++) {
		minSet.insert(arr[i]);
	}
	minX[0] = *minSet.begin();
	
	contNum = 0; paintNum = 0; restSpace = 0;
	for (int i = 0; i <= N - X; i++) { //X 연속 min값 계산
		if (i > 0) {
			minSet.erase(minSet.find(arr[i - 1]));
			minSet.insert(arr[i + X - 1]);
			minX[i] = *minSet.begin();
		}

		if (i != 0 && minX[i - 1] == minX[i] && contNum < X && i != N - X) {
			contNum++;
		}
		else {
			contNum = 0;
			paintNum++;
		}
		restSpace += arr[i] - minX[i];
	}

	for (int i = N - X + 1; i < N; i++) {
		restSpace += arr[i] - minX[N - X];
	}
	

	cout << restSpace << "\n" << paintNum << "\n";

}