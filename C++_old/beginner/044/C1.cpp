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
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int N,x,A,y[NMAX+1];
ll  dp[NMAX+1][5005];
void solve1(){
    memset(dp,0,sizeof(dp));
    dp[0][N*NMAX]=1;
    
    for(int j=1;j<=N;j++){
        for(int t=0;t<=2*N*NMAX;t++){
            if(t-y[j]>=0&&t-y[j]<=2*N*NMAX)
                dp[j][t]=dp[j-1][t]+dp[j-1][t-y[j]];
            else
                dp[j][t]=dp[j-1][t];
        }
    }
}



int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>A;
    for(int i=1;i<=N;i++){
        cin>>x;
        y[i]=x-A;
    }
    
    solve1();
    
    
    cout<<dp[N][N*NMAX]-1<<"\n";
    
    return 0;
}
