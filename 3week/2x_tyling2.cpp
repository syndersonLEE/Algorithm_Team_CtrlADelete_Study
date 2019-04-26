/*Question 11727 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#define MAX_NUM 10001
using namespace std;
int box[MAX_NUM];
int main() {
	box[1] = 1;
	box[2] = 3;
	int n;
	cin >> n;
	for (int i = 3;i <= n;i++)
		box[i] = (box[i - 1] + 2 * box[i - 2])%10007;
	cout << box[n] << endl;
}