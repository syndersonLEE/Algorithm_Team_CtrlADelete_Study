#include<iostream>
#include<string>
using namespace std;
class suffix{
	bool *letter_check;
	string word;
public:
	void order_dic();
};
void suffix::order_dic(){
	cin>>word;
	letter_check = new bool[word.size()];
	for(int i=0;i<word.size();i++) // initialize
		letter_check[i] = false;
	for(int i=0;i<word.size();i++){ //i== checking number
		int min=-1;
		for(int j=0;j<word.size();j++){ //j== word length
			if(letter_check[j]==false){
				if(min==-1){ //set min
					min=j;
					continue;
				}
				for(int k=0;;k++){ 
					if(word[j+k]=='\0'||word[j+k]<word[min+k]){
						min = j;	 
						break;
					}
					else if(word[min+k]=='\0'||word[j+k]>word[min+k])
						break;	
				}
			}
		}
		letter_check[min]=true;		//print
		for(int k = min;k<word.size();k++)
			cout<<word[k];
		cout<<endl;
	}
};

int main(){
	suffix su;
	su.order_dic();
	return 0;
}