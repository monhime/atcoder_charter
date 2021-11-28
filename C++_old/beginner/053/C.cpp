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
ll x;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>x;
    
    ll a=x%11;
    
    if(a>0&&a<=6)cout<<x/11*2+1<<"\n";
    else if(x==0)cout<<0<<"\n";
    else if(a>=7&&a<=10) cout<<x/11*2+2<<"\n";
    else cout<<x/11*2<<"\n";
    
    return 0;
}
