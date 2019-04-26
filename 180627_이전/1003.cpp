//피보나치 함수 BaekJoon Solved by 이상윤

#include<iostream>
#include<algorithm>

using namespace std;

int fibonacci(int n,int &fib_1,int &fib_2) { //피보나치 함수
	if (n == 0) {
		fib_1++;
		return 0;
	}
	else if (n == 1) {
		fib_2++;
		return 1;
	}
	else {
		return fibonacci(n-1,fib_1,fib_2) + fibonacci(n-2,fib_1,fib_2);
	}
}

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		int fib_count;
		cin >> fib_count;
		int fib_1 = 0; 
		int fib_2 = 0;
		fibonacci(fib_count, fib_1, fib_2);
		cout << fib_1 << " " << fib_2 << endl;
	}
	return 0;
}