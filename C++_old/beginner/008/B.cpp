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
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map <string,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int N,maxn;

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    string s;
    cin>>N;
    
    for(int i=0;i<N;i++){
        cin>>s;
        mp[s]++;
    }
    
    string max_p;
    for(auto p:mp){
        if(maxn<p.second){
            maxn=p.second;
            max_p=p.first;
        }
    }
    cout<<max_p<<"\n";
    
    return 0;
}
