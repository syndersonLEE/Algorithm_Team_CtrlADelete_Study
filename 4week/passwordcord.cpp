/*Question 2011 암호 코드 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<string>
#define MAX_NUM 5015
#define DIV_NUM 1000000
using namespace std;
long long box[MAX_NUM];
string a;

long long pass_code(int n) {
	if (box[n]!=0)	
		return box[n];
	else {
		int curr_num = (a[n - 1] - '0');
		if (n >= 2)
			curr_num += 10 * (a[n - 2] -'0');
		if (a[n - 1] > '0')
			box[n] += pass_code(n - 1)%DIV_NUM;
		if (10 <= curr_num&&curr_num <= 26)
			box[n] += pass_code(n - 2) % DIV_NUM;
		return box[n] % DIV_NUM;
	}
}

int main() {
	cin >> a;
	fill(box, box + 5015, 0);
	box[0] = 1;
	box[1] = 1;
	if (a == "0")
		cout << 0 << endl;
	else 
		cout << pass_code(a.size()) << endl;
	
}