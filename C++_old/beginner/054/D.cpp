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
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=10;
static const int MOD=1e9+7;
static const int NMAX=40;
static const int MMAX=0;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int a[NMAX],b[NMAX],c[NMAX],N,Ma,Mb;

int dp[NMAX+1][NMAX*MAX+1][NMAX*MAX+1]; //i-1までの組み合わせで、ca g cb gのときの最小コスト
void solve(){
    for(int i=0;i<=N;i++){
        for(int ca=0;ca<=NMAX*MAX;ca++){
            for(int cb=0;cb<=NMAX*MAX;cb++) dp[i][ca][cb]=INF;
        }
    }
    dp[0][0][0]=0;
    for(int i=0;i<N;i++){
        for(int ca=0;ca<=NMAX*MAX;ca++){
            for(int cb=0;cb<=NMAX*MAX;cb++){
                if(dp[i][ca][cb]==INF) continue;//ca,cbの組み合わせがまだない
                //この前のca,cbループで記録されたものと比較
                dp[i+1][ca][cb]  = min(dp[i+1][ca][cb],dp[i][ca][cb]); //iを加えない
                dp[i+1][ca+a[i]][cb+b[i]] = min(dp[i+1][ca+a[i]][cb+b[i]],dp[i ][ca][cb]+c[i]);//iを加える
             }
        }
    }
    int ans = INF;
    for(int ca = 1;ca<=NMAX*MAX;ca++){
        for(int cb = 1;cb<=NMAX*MAX;cb++){
            if(ca*Mb==cb*Ma) ans=min(ans,dp[N][ca][cb]); //ca:cb=Ma:Mbとなるすべての組み合わせを確かめる
        }
    }
    if(ans == INF) ans = -1;
    cout<<ans<<"\n";
    
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N>> Ma >> Mb;
    for(int i=0;i<N;i++) cin >> a[i] >> b[i] >> c[i];

    solve();
    
    return 0;
}
