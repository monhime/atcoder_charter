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
map <int,int> mp;
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int N,K,l,r,s[MAX+1],max_l;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>K;
    for(int i=0;i<N;i++) {
        cin>>s[i];
        if(s[i]==0){
            cout<<N<<"\n";
            return 0;
        }
    }
    ll mul=1;
    for(int l=0;l<N;l++){
        if(r<l){mul=1;r=l;}
        while(r<N&&mul*s[r]<=K) {
            mul*=s[r++];
        }
        //rはlに対してs[r]を満たさない最小の整数
        max_l=max(max_l,r-l);
        mul/=s[l];
    }

    cout<<max_l<<"\n";
    
    
    return 0;
}
