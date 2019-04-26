/*Question 2331 반복수열 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	vector<int> box(100000);
	int p;
	cin >> box[0] >> p;
	int i = 0;
	while (1) {
		int temp = box[i];
		int part_num[5];
		int repeat_num = 0;
		for (int k = 0;k < 5;k++) {
			part_num[k] = temp % 10;
			temp /= 10;
			repeat_num += pow(part_num[k], p);
		}
		box[++i] = repeat_num;
		int j = i;
		bool check = true;
		while (j) {
			j--;
			if (box[j] == box[i]) {
				check = false;
				break;
			}
		}
		if (!check) {
			cout << j << "\n";
			break;
		}
	}
	
	return 0;
}