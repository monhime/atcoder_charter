#include<iostream>
#include<string>
using namespace std;
int main(){
    int ab[26]={};
    string s;
    while(getline(cin,s)){
        for(int i=0;i<s.size();i++){
            if(s[i]>='a'&&s[i]<='z')ab[s[i]-'a']++;
            else if(s[i]>='A'&&s[i]<='Z')ab[s[i]-'A']++;
        }    
            
    }
    for(int i=0;i<26;i++){
        cout<<(char)('a'+i)<<" "<<":"<<" "<<ab[i]<<"\n";
    }
    return 0;
}
