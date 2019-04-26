//solved By SANGYUNLEE

#include<iostream>
#include<stack>
#include<queue>

using namespace std;

stack<int> st;
queue<char> q;

int testCases;
int arr[100001];
int numState;

int main() {
	cin >> testCases;
	for (int i = 0; i < testCases; i++) {
		cin >> arr[i];
	}

	numState = 0;
	for (int i = 1; i <= testCases; i++) {
		st.push(i);
		q.push('+');
		while (!st.empty() && (st.top() == arr[numState])) {
			st.pop();
			q.push('-');
			numState++;
		}
	}

	if (!st.empty()) {
		cout << "NO\n";
	}
	else {
		while (!q.empty()) {
			cout << q.front() << "\n";
			q.pop();
		}
	}
	return 0;
}