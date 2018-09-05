#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main(){
	ifstream infile;
	infile.open ("Dictionary.txt");
        while(!infile.eof()){
            string STRING;
	        getline(infile,STRING); // Saves the line in STRING.
	        mp[STRING]++;
        }
	infile.close();
    /*map<string,int>::iterator it;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first;
    }*/
    return 0;
}
