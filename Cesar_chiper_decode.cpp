#include<bits/stdc++.h>
using namespace std;
vector<char>input;
vector<char>output[26];
map<string,int>mp;
int fitness[26]={0};
vector<char>word;

void dictionary(){
	ifstream infile;
	infile.open ("Dictionary.txt");
        while(!infile.eof()){
            string STRING;
	        getline(infile,STRING); // Saves the line in STRING.
	        mp[STRING]++;
        }
	infile.close();
}
int main(){
    dictionary();

    int shift,mx=0,ans=0;
    char ch;
	freopen("cesarout.txt","r",stdin);
	freopen("decoded.txt","w",stdout);
    while(scanf("%c",&ch)!=EOF){
        if(ch>='A'&&ch<='Z'){
            ch+=32;
        }
        input.push_back(ch);
    }
    for(shift=0;shift<26;shift++){
        int pointer=0;
        for(int i=0;i<input.size();i++){
            if(input[i]>='a'&&input[i]<='z'){
                output[shift].push_back((input[i]-'a'-shift+26)%26+'a');

                word.push_back((input[i]-'a'-shift+26)%26+'a');
            }
            else{
                output[shift].push_back(input[i]);

                pointer=i+1;
                string s(word.begin(),word.end());
                if(mp[s]>0){
                    fitness[shift]++;
                }
                word.clear();
            }
        }
        /*for(int i=0;i<output[shift].size();i++){
            printf("%c",output[shift][i]);
        }
        printf("\n\n\n %d \n\n\n",fitness[shift]);*/
        if(mx<fitness[shift]){
            mx=fitness[shift];
            ans=shift;
        }
    }


    printf("Key is %d\n\n",ans);

    for(int i=0;i<output[ans].size();i++){
        printf("%c",output[ans][i]);
    }

    return 0;
}
