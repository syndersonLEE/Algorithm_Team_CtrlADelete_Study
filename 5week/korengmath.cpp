/*Question 10814 나이순 정렬 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Order {
public:
	string name;
	int kor_score, eng_score, math_score;
	Order(string name, int kor,int eng, int math) {
		this->name = name;
		kor_score = kor;
		eng_score = eng;
		math_score = math;
	}
};
bool operator < (const Order &a, const Order &b) {
	if (a.kor_score != b.kor_score)
		return a.kor_score>b.kor_score;
	else {
		if (a.eng_score != b.eng_score)
			return a.eng_score < b.eng_score;
		else {
			if (a.math_score != b.math_score)
				return a.math_score > b.math_score;
			else {
				return a.name.compare(b.name) < 0;
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	string a;
	int b,c,d;
	vector<Order> box;
	for (int i = 0;i < n;i++) {
		cin >> a >> b >> c >> d;
		box.push_back(Order(a,b,c,d));
	}
	sort(box.begin(), box.end());
	for (int i = 0;i < box.size();i++)
		cout << box[i].name + "\n";
	return 0;
}