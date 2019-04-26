/*Question 1912 ¿¬¼ÓÇÕ in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 100002
using namespace std;

long long box[MAX_NUM];
int cost[MAX_NUM];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> cost[i];
		box[i] = cost[i];
	}
	for (int i = 2;i <= n;i++) 
		box[i] = max(box[i], box[i - 1] + cost[i]);

	long long ans = box[1];
	for (int i = 2;i <= n;i++)
		ans = max(ans, box[i]);
	cout << ans << endl;
		
}