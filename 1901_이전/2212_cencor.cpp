#include<iostream>
#include<algorithm>

using namespace std;

int N, K;
int sensor[10001];
int distSens[10000];
int totLong;

int main() {
	ios::sync_with_stdio(false);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> sensor[i];
	}
	sort(sensor, sensor + N);
	totLong = sensor[N - 1] - sensor[0];
	for (int i = 0; i < N - 1; i++) {
		distSens[i] = -(sensor[i + 1] - sensor[i]);
	}
	sort(distSens, distSens + (N - 1));

	for (int i = 0; i < K - 1; i++) {
		totLong += distSens[i];
	}

	cout << totLong << "\n";
	
	
}