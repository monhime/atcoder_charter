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
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,Q,K;
typedef struct edge{
    int to,cost;
}Edge;
vector<Edge> adj[MAX+2];
ll d[MAX+2]; //Kからの距離
bool visited[MAX+2];
void dfs(int v,int u,ll dist){ //次の場所、今の場所,そこのkからの距離
    d[v]=dist;
    for(auto &e: adj[v]){
        if(e.to==u)continue; //元の場所に戻るなら
        dfs(e.to,v,dist+e.cost);

    }
    
}

void solve(){
    visited[K]=true;
    d[K]=0;
    dfs(K,-1,0ll);
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0;i<N-1;i++){
        int a,b,c;
        cin>>a>>b>>c;
        
        adj[a].push_back((Edge){b,c});
        adj[b].push_back((Edge){a,c}); //反対向きがあることに注意!!
    }
    cin>>Q>>K;
    solve();
    

    while(Q--){
        int x,y;
        cin>>x>>y;
        cout<<d[x]+d[y]<<"\n";
        
    }
    
    return 0;
}
