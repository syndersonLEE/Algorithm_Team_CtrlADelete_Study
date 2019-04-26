#include<iostream>

using namespace std;

void order(int a) {
	for (int i = a;i != 0;i--) 
		cout << "i\n";
}
int main() {
	int i;
	order(i);
	return 0;
}