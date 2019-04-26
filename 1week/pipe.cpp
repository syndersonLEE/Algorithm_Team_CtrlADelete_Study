#include<iostream>
#include<string>
#include<stack>
#define MAX_SIZE 255;
using namespace std;
class pipe{
	stack<char> st;
	int pieces;
public:
	pipe(){
		pieces = 0;
	}
	void check_pieces();
};
void pipe::check_pieces(){
	string a;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]=='(')
			st.push(a[i]);
		else{
			st.pop();
			if(a[i-1]=='(')
				pieces+=st.size();
			else
				pieces++;
		}
	}
	cout<<pieces<<endl;
}
int main(){
	pipe pi;
	pi.check_pieces();
	return 0;
}