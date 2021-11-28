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
int N,A,x[NMAX+1];
ll dp[NMAX+1][NMAX+1][5002],sum;

/*
 動的計画法
 */

//再利用なし三次元

void solve(){
    memset(dp,0,sizeof(dp)); //全て0で初期化
    dp[0][0][0]=1ll; //j=0,k=0,s=0の時は何も選ばないもので、1通り。最後に引く(入れないで加算)
    
    for(int j=1;j<=N;j++){
        for(int k=0;k<=N;k++){ //x1~xiのうち使う枚数
            for(int s=0;s<=N*A;s++){ //
                if(k>=1&&s>=x[j]) dp[j][k][s]=dp[j-1][k][s] + dp[j-1][k-1][s-x[j]];
                else if(s<x[j]) dp[j][k][s] = dp[j-1][k][s];
            }
        }
    }
}

    
    
    
}
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>A;
    for(int i=1;i<=N;i++) cin>>x[i];
    
    solve();


    for(int i=1;i<=N;i++) sum+=dp[N][i][i*A];
    
    cout<<sum<<"\n";
    
    return 0;
}
