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
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,M;
vector<P> adj[MAX+2]; //隣接リスト
int visited[MAX+2];
ll dist[MAX+2];

void dfs(int u){
    visited[u]=1;
    
    for(int i=0;i<adj[u].size();i++){
        int v=adj[u][i].first;
        int d=adj[u][i].second;
        
        if(visited[v]) continue;
        dist[v]=dist[u]+d; //一回目に訪れたときだけ距離を記録
        dfs(v);
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>M;
    //一度グラフ構造を記録
    for(int i=0;i<M;i++){
        int u,v,d;
        cin>>u>>v>>d;
        u--; v--;
        
        adj[u].push_back(P(v,d));
        adj[v].push_back(P(u,-d));
    }
    
    for(int i=0;i<N;i++){
        if(!visited[i]){//隔離されている部分の数だけ実行される。
            dist[i]=0;
            dfs(i);
        }
    }
    for(int u=0;u<N;u++){
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i].first;
            int d=adj[u][i].second;
            
            if(dist[v]!=dist[u]+d){ //他の行き方でも距離が同じか確かめる
                cout<<"No"<<"\n";
                return 0;
            }
        }
    }
    cout<<"Yes"<<"\n";
    return 0;
}
