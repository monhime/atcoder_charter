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
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int N;
int d[MAX];
vector<P> adj[MAX]; //<隣接地点,その地点の最短距離>
void dijkstra(int s){
    priority_queue<P> PQ; //<最短距離*-1,場所>
    int color[MAX];
    for(int i=0;i<N;i++){
        d[i]=INF;
        color[i]=WHITE;
    }
    
    d[s]=0;
    PQ.push(make_pair(0,0));
    color[0]=GRAY;
    
    while(!PQ.empty()){
        P f=PQ.top(); PQ.pop();
        int u=f.second; //次に行く場所の候補
        
        color[u]=BLACK;
        
        if(d[u]<f.first*(-1)) continue; //候補の今の時点の最短距離が、記録されてるのより小さい
        
        for(int j=0;j<adj[u].size();j++){
            int v=adj[u][j].first; //uのj番目の隣接地点のインデックス
            if(color[v]==BLACK) continue; //もう行った
            if(d[v]<=d[u]+adj[u][j].second)continue;//vにはもっと早い行き方がある
            d[v]=d[u]+adj[u][j].second;
            PQ.push(make_pair(d[v]*(-1),v));
            color[v]=GRAY;
        }
        
    }
}


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    int k,u,v,c;
    
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>u>>k;
        for(int j=0;j<k;j++){
            cin>>v>>c;
            adj[u].push_back(make_pair(v,c));
        }
    }
    dijkstra(0);
    for(int i=0;i<N;i++)
        cout<<i<<" "<<(d[i]==INF?-1:d[i])<<"\n";
    
    return 0;
}
