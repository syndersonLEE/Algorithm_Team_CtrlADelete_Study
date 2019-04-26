#include<iostream>
using namespace std;
class alpha_where{
	char word[100];
	int w_where[26];
public:
	alpha_where(){
		for(int i=0;i<26;i++){
			w_where[i]=-1;
		}
	}
	void alpha_num();
};
void alpha_where::alpha_num(){
	cin>>word;
	for(int i=0;word[i]!='\0';i++){
		if(w_where[word[i]-97]==-1)
			w_where[word[i]-97]=i;
	}
	for(int i=0;i<26;i++){
		cout<<w_where[i]<<" ";
	}
	cout<<endl;
};

int main(){
	alpha_where alpha;
	alpha.alpha_num();
	return 0;
}