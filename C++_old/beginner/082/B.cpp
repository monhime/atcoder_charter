#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
using namespace std;
int main(){
    string s,t;

    cin>>s>>t;

    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<char>());

    if(s<t)cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;
}

