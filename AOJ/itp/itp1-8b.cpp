#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
    string s;
    while(cin>>s&&s!="0"){
        int num=0;
        for(int i=0;i<s.size();i++)
            num+=s[i]-'0';
        cout<<num<<"\n";    
    }
    return 0;
    
}
