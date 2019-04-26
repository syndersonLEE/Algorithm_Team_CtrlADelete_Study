#include<iostream>
#include<string>
using namespace std;
class string_type{
	string word;
	int type_word[26];
public:
	string_type(){
		for(int i=0;i<26;i++){
			type_word[i]=-1;
		}
	}
	void check_string();
};
void string_type::check_string(){
	while(1){
		for(int i=0;i<26;i++){
			type_word[i]=-1;
		}
		getline(cin,word);
		if(word=="\0")
			break;
		for(int i=0;word[i]!='\0';i++){
			if(type_word[word[i]-97]==-1)
			type_word[word[i]-97]=i;
		}
		for(int i=0;i<26;i++)
			cout<<type_word[i]<<" ";
		cout<<endl;
	}
};

int main(){
	string_type st;
	st.check_string();
	return 0;
}