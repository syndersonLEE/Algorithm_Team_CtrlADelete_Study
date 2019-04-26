#include <string>
#include <iostream>
using namespace std;

class vps{
	int num;
	bool check;
public:
	vps(){
		num = 0;
		check = true;
	}
	void push_vps();
	void check_vps();
};
void vps::push_vps(){

	string a;
	int b = -1;
	cin>>a;
	while(a[++b]!='\0'){
		if(a[b]=='(')
			num++;
		else if(a[b]==')'&&num>0)
			num--;
		else
			check = false;
	}
}
void vps::check_vps(){
	if(num==0&&check==true)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main(void){
	int a;
	cin>>a;	
	while(a--){
		vps v;
		v.push_vps();
		v.check_vps();	
	}
	return 0;	
}