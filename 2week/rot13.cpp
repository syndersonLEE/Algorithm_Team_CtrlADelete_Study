#include<iostream>
#include<string>
using namespace std;
class num_sum{
	unsigned int
public:	
	void rot_check();
};
void rot13::rot_check(){
	cin.getline(word,100);
	for(int i=0;word[i]!='\0';i++){
		if((65<=word[i]&&word[i]<=90)){
			if(word[i]+13>90)	
				word[i]-=26;
			word[i]+=13;
		}
		else if((97<=word[i]&&word[i]<=122)){
			if(word[i]+13>122)
				word[i]-=26;
			word[i]+=13;	
		}
	}
	for(int i=0;word[i]!='\0';i++)
		cout<<word[i];
	cout<<" "<<endl;
};

int main(){
	rot13 rot;
	rot.rot_check();
	return 0;
}