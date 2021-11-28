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
int N,a[MAX];
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) cin>>a[i];
    int l,r=0;
    ll ans=0;
    for(l=0;l<N;l++){
        if(l>r)r=l;
        while(r+1<N&&a[r+1]>a[r])r++;
        //rは(l,r)を満たす最大のr
        ans+=r-l+1;
    }
    
    
    cout<<ans<<"\n";
    return 0;
}

