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

deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=2e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int N,Q;
ll a[MAX+2];
int l,r;
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>Q;
    for(int i=0;i<Q;i++){
        cin>>l>>r;
        a[l]++; a[r+1]--;
    }
    for(int i=1;i<N+1;i++){
        a[i]+=a[i-1];
        cout<<(a[i]&1?1:0);
    }
    cout<<"\n";
    
    return 0;
}
