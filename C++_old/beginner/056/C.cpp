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
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
ll X;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>X;
    
    ll l=0ll,r=1e5;
    while(r-l>1){
        ll m=(l+r)/2; //r=l+1の時m=l
        if(m*(m+1)>2*X)r=m;
        else l=m;
    }
    
    if(l*(l+1)==2*X)cout<<l<<"\n";
    else cout<<r<<"\n";
    
    return 0;
}
