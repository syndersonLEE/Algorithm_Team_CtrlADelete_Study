/*Question 2225 ÇÕºÐÇØ in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#define MAX_NUM 202
using namespace std;
long long box[MAX_NUM][MAX_NUM];
long long s_d(int n,int k) {
	if (k == 1)
		return 1;
	if (box[n][k] != 0)
		return box[n][k];
	else {
		for (int i = 0;i <= n;i++) {
			box[n][k] += s_d(i, k - 1)%1000000000;
		}
		return box[n][k] % 1000000000;
	}

}

int main() {
	int a, b;
	cin >> a>> b;
	cout << s_d(a, b) << endl;
}