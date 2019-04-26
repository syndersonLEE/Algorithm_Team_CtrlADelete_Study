#include<iostream>
#include<vector>

using namespace std;

int n, k, temp;
int coinBox[100001];
vector<int> coin;

void numCheck(int cnt, int curNum) {
	if (cnt != 3) {
		int temp = curNum;
		for(int i = 0; i  )
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> temp;		
		coin.push_back(temp);
	}
	numCheck(0);
	cout << coinBox[k] << "\n";
}