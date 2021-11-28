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
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
vector <char> S;

int main(){
    string s; cin>>s;
    
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')S.push_back('0');
        else if(s[i]=='1')S.push_back('1');
        else if(S.size()) S.pop_back();
    }
    for(int i=0;i<S.size();i++)
        cout<<S[i];
    
    cout<<"\n";
    return 0;
}

