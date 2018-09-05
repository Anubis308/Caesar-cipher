#include<bits/stdc++.h>
using namespace std;
vector<char>input;
vector<char>output;
int main(){
    ifstream infile;
    char ch;
	infile.open ("cesarin.txt");
	freopen("cesarout.txt","w",stdout);
    while(!infile.eof()){
        infile.get(ch);
        if(ch>='A'&&ch<='Z'){
            ch+=32;
        }
        input.push_back(ch);
    }
    infile.close();

    int shift;
    scanf("%d",&shift);
    for(int i=0;i<input.size();i++){
        //printf("%c",input[i]);
        if(input[i]>='a'&&input[i]<='z'){
            output.push_back((input[i]-'a'+shift)%26+'a');
        }
        else{
            output.push_back(input[i]);
        }
    }
    for(int i=0;i<output.size();i++){
        printf("%c",output[i]);
    }
    return 0;
}
