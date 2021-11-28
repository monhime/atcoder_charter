#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
using namespace std;

int main(){
    string s,t;
    cin>>s>>t;
    int cnt=0;
    string res="";
    int s_size=s.size();
    int t_size=t.size();
    for(int i=s_size-t_size;i>=0;i--){
        for(int k=0;k<i;k++){
            if(s[k]=='?'){
                res+="a";//文字列の配列に追加
            }else{
                res+=s[k];
            }
        }
        for(int j=0;j<t_size;j++){
            if(s[j+i]=='?')
                res+=t[j];
            else if(s[j+i]==t[j])
                res+=t[j];       
            else{
                res="";
                goto B;//Bのとこへ行く
            }    
        }
        for(int k=i+t_size;k<s_size;k++){
            if(s[k]=='?')res+="a";//?だったらa
            else res+=s[k];//?でなければs[]
        }
        cout<<res<<"\n";
        return 0;
        B:;
    }
    cout<<"UNRESTORABLE"<<"\n";
    return 0;
}
