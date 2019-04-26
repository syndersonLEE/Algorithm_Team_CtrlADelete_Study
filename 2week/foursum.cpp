#include<iostream>
using namespace std;
class four_num{
	long long num;
	int a,b,c,d;
public:	
	four_num(){
		num = 0;
	}
	void four_sum();
};
void four_num::four_sum(){
	int temp1=1;
	int temp2=1;
	cin>>a>>b>>c>>d;
	num+=(b+d);
	while(b){
		b/=10;
		temp1*=10;
	}
	num+=(long long)temp1*a;
	while(d){
		d/=10;
		temp2*=10;
	}
	num+=(long long)temp2*c;
	cout<<num<<endl;
};

int main(){
	four_num fo;
	fo.four_sum();
	return 0;
}