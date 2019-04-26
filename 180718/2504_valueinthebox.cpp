//Solved By SANGYUNLEE

#include<stdio.h>
#include<stack>

using namespace std;

int valState = 0;
bool errorCheck = false;
char c[31];
stack<int> st;
stack<int> exp;

int main() {
	scanf("%s", c);
	for (int i = 0; c[i] != '\0'; i++) {
		if (c[i] == '(') {
			st.push(-1);
			if (valState) {
				st.push(valState);
				valState = 0;
			}
		}
		else if (c[i] == '[') {
			st.push(-2);
			if (valState) {
				st.push(valState);
				valState = 0;
			}
		}
		else if (c[i] == ')') {
			if (st.top() == '[') {
				errorCheck = true;
				break;
			}
			else if (c[i - 1] == '(') {
				valState = 2;
			}
			else if (st.top() == '(') {
				valState *= 2;
			}
			else {
				
			}
		}
		else {
			if (st.top() == '(') {
				errorCheck = true;
				break;
			}
		}
	}
}