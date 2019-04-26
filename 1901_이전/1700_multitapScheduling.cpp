#include<stdio.h>
#include<queue>

using namespace std;

int usingPlug[101], app[101];
int n, k, temp, usedPlug = 0, ans = 0;


int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d", &app[i]);
	}

	for (int i = 0; i < k; i++) {
		bool usedCheck = false;
		for (int j = 0; j < usedPlug; j++) {
			if (usingPlug[j] == app[i]) {
				usedCheck = true;
				break;
			}
		}
		
		if (!usedCheck) {
			if (usedPlug != n) {
				usingPlug[usedPlug] = app[i];
				usedPlug++;
			}
			else {
				pair<int, int> lru = { -1, -1 };//index, val
				for (int j = 0; j < n; j++) {
					int term = 0;
					for (int m = i + 1; m < k && usingPlug[j] != app[m]; m++) {
						term++;
					}
					if (term > lru.second) {
						lru.first = j;
						lru.second = term;
					}
				}
				usingPlug[lru.first] = app[i];
				ans++;
			}
		}
		
	}

	printf("%d\n", ans);

}