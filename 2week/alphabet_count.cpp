#include<iostream>
#include<string>
using namespace std;
class alphabet{
	char word[100];
	int w_count[26];
public:
	alphabet(){
		for(int i=0;i<26;i++){
			w_count[i]=0;
		}
	}
	void alpha_num();
};
void alphabet::alpha_num(){
	cin>>word;
	for(int i=0;word[i]!='\0';i++){
		w_count[word[i]-97]++;
	}
	for(int i=0;i<26;i++){
		cout<<w_count[i]<<" ";
	}
	cout<<endl;
};

int main(){
	alphabet alpha;
	alpha.alpha_num();
	return 0;
}