#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <char,int> mp1,mp2;
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int n;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>n;
    string s[n];
    
    for(int i=0;i<n;i++)cin>>s[i];
        
    for(int i=0;i<s[0].size();i++) mp1[s[0][i]]++;
    
    for(int i=1;i<n;i++){
        for(int j=0;j<s[i].size();j++){
            mp2[s[i][j]]++;
        }
        for(auto p:mp1){
            if(mp2[p.first]<p.second)mp1[p.first]=mp2[p.first];
        }
        mp2.clear();
    }
    
    for(auto p:mp1){
        for(int i=0;i<p.second;i++)cout<<p.first;
    }
    cout<<"\n";
    return 0;
}
