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
#define EPS (1e-10)
using namespace std;
map <char,bool> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=100;

int main(){
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]){
            cout<<"no"<<"\n"; 
            return 0;
        }else mp[s[i]]=true;     
    }
    cout<<"yes"<<"\n";
    return 0;
}

