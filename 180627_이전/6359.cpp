#include <iostream>
#include <algorithm>
#define MAX_NUM
using namespace std;

int sb(int n, int *room);

int main() {
	int tc,round;
	while (tc--) {
		cin >> round;
		bool room[MAX_NUM] = { false };
		int ans = sb(round,room);
		cout << ans << endl;
	}
}

int sb(int n,bool *room) {
	while()
}

/*input 방의 개수 -> 배열 

*/