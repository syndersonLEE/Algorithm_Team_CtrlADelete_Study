#include <string>
#include <iostream>
#define MAX_STACK 255
using namespace std;

class stack{
	int point;
	int arr[MAX_STACK];
public:
	stack(){
		point = -1;
	}
	void push();
	void pop();
	void size();
	void empty();
	void top();
};
void stack::push(){
	int a;
	cin>>a;
	arr[++point] = a;
}
void stack::pop(){
	if(point!=-1)
		cout<<arr[point--]<<endl;
	else
		cout<<-1<<endl;
}
void stack::size(){
	cout<<point+1<<endl;
}
void stack::empty(){
	if(point==-1)
		cout<<1<<endl;
	else
		cout<<0<<endl;
}
void stack::top(){
	if(point==-1)
		cout<<-1<<endl;
	else
		cout<<arr[point]<<endl;
}


int main(void){
	stack st;
	int b;
	string a;
	cin>>b;
	while(b--){
		cin>>a;
		if(a=="push")
			st.push();
		else if(a=="pop")
			st.pop();
		else if(a=="size")
			st.size();
		else if(a=="empty")
			st.empty();
		else if(a=="top")
			st.top();
		else
			continue;
	}
		return 0;	
}