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
#define INF (1<<30)
using namespace std;
static const int MAX=100000;

int main(){
    string s,t;
    cin >>s>>t;
    int s_size=s.size();
    int t_size=t.size();
    int flag=-1;
    //全てのTの文字列の位置をSの後ろから総当たりする。
    //もしあればその前?？をすべてa
    if(s_size<t_size){
        cout<<"UNRESTORABLE"<<"\n";
        return 0;
    }
    for(int i=s_size-t_size;i>=0;i--){
        if(s[i]!='?'&&s[i]!=t[0])continue;
        for(int j=0;j<t_size;j++){
            if(s[i+j]=='?'&&j!=t_size-1)continue;
            if(s[i+j]=='?'&&j==t_size-1)flag=i;
            if(s[i+j]!=t[j])break;
        }
        if(flag!=-1)break;
    }
    if(flag==-1){
        cout<<"UNRESTORABLE"<<"\n";
        return 0;
    }


    for(int i=0;i<flag;i++){
        if(s[i]!='?')cout<<s[i];
        else cout<<(s[i]=='?'?'a':s[i]);
    }
    for(int i=0;i<t_size;i++)
        cout<<t[i];
    for(int i=flag+t_size;i<s_size;i++)
        cout<<(s[i]=='?'?'a':s[i]);


    return 0;
}
