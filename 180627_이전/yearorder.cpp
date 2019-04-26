/*Question 10814 나이순 정렬 in BaekJoon Online Judge
Solved by Lee Sang Yun                  */
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class Order {
public:
	int age;
	string name;
	Order(int age, string name) {
		this->age = age;
		this->name = name;
	}
};
bool operator < (const Order &a, const Order &b) {
	return a.age < b.age;
}
int main() {
	int n;
	cin >> n;
	int a;
	string b	;
	vector<Order> box;
	for (int i = 0;i < n;i++) {
		cin >> a >> b;
		box.push_back(Order(a, b));
	}
	stable_sort(box.begin(), box.end());
	for (int i = 0;i < box.size();i++)
		cout << box[i].age << " " << box[i].name << endl;
	return 0;
}