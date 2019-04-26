#include<iostream>
#include<string>
using namespace std;
class string_type{
	string word;
	int type_word[4];
public:
	string_type(){
		for(int i=0;i<4;i++){
			type_word[i]=0;
		}
	}
	void check_string();
};
void string_type::check_string(){
	while(1){
		for(int i=0;i<4;i++){
			type_word[i]=0;
		}
		getline(cin,word);
		if(word=="\0")
			break;
		for(int i=0;word[i]!='\0';i++){
			if(65<=word[i]&&word[i]<=90)
				type_word[1]++;
			else if(97<=word[i]&&word[i]<=122)
				type_word[0]++;
			else if(48<=word[i]&&word[i]<=57)
				type_word[2]++;	
			else if(word[i]&&word[i]==' ')
					type_word[3]++;
		}
		for(int i=0;i<4;i++)
			cout<<type_word[i]<<" ";
		cout<<endl;
	}
};

int main(){
	string_type st;
	st.check_string();
	return 0;
}