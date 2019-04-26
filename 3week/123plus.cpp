/*Question 9095 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#define MAX_NUM 10001
using namespace std;
int box[MAX_NUM];

int plus_three(int a) {
	if (a == 1)
		return box[a] = 1;
	if (a == 2)
		return box[a] = 2;
	if (a == 3)
		return box[a] = 4;
	if (box[a] != -1)
		return box[a];
	else
		return plus_three(a - 1) + plus_three(a - 2) + plus_three(a - 3);
}
int main() {
	fill(box, box + MAX_NUM, -1);
	int x,y;
	cin >> x;
	while (x--) {
		cin >> y;
		cout << plus_three(y) << endl;
	}
	return 0;
}