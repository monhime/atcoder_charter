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
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map <char,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;

int main(){
    string s; cin>>s;

    for(int i=0;i<s.size();i++) mp[s[i]]++;  
    
    for(int i=0;i<6;i++)
        cout<<(!i?"":" ")<<mp['A'+i];
    cout<<"\n";    
    return 0;
}


