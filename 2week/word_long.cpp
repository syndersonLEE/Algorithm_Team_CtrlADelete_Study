#include<iostream>
#include<string>
using namespace std;
class word_long{
	string word;
public:
	void length_check();
};
void word_long::length_check(){
	cin>>word;
	cout<<word.length()<<endl;
};

int main(){
	word_long wo;
	wo.length_check();
	return 0;
}