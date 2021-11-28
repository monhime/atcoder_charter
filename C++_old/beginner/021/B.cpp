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
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int N,a,b,K,P;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>a>>b>>K;

    mp[a]++; mp[b]++;
    for(int i=0;i<K;i++){
        cin>>P;
        mp[P]++;
    }
    
    for(auto p:mp){
        if(p.second>=2){
            cout<<"NO"<<"\n";
            return 0;
        }    
    }
    cout<<"YES"<<"\n";
    return 0;
}


