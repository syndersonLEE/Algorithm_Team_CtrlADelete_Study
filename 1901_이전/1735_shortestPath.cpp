#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct WAY {
	int end;
	int val;
};

int V, E, startNum, from, to, tempVal;

vector<WAY> arr[300001];
int dist[20001];

int main() {
	cin >> V >> E >> startNum;
	for (int i = 0; i < E; i++) {
		cin >> from >> to >> tempVal;
		arr[from].push_back({ to, tempVal });
	}

	for (int i = 0; i < V; i++) {
		dist[i] = 10E
	}
}