#include <string>
#include <iostream>
#define MAX_STACK 255
using namespace std;

class stack{
	int top;
	int stack[MAX_STACK];
public:
	stack(){
		top = -1;
	}
	void push();
	void pop();
	void size();
	void empty();
	void top();
}
void stack::push(){
	int a;
	cin>>a;
	stack[++top] = a;
}
void stack::pop(){
	cout<<stack[top--]\n;
}
void stack::size(){
	cout<<top+1\n;
}
void stack::empty(){
	if(top==-1)
		cout<<1\n;
	else
		cout<<0\n;
}
void stack::top(){
	if(top==-1)
		cout<<-1\n;
	else
		cout<<stack[top]\n;
}


int main(void){
	int b;
	string a;
	cin>>b;
	while(b--){
		cin>>a;
		stack st;
		if(a=="push")
			st.push();
		else if(a=="pop")
			st.pop();
		else if(a=="size")
			st.size();
		else if(a=="empty")
			st.empty();
		else if(a=="top")
			st.pop();
		else
			continue;
	}
		return 0;	
}