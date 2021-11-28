#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
//#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a=0,b=0,c=0;
    for(int i=0;i<3;i++){
        if(s[i]=='a')a++;
        if(s[i]=='b')b++;
        if(s[i]=='c')c++;

    }
    if(a==1&&b==1&&c==1)
        cout<<"Yes"<<"\n";
    else 
        cout<<"No"<<"\n";
    return 0;
}

