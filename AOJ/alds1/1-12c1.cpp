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

map <int,int> mp;

#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};

typedef pair<int, int> P; //最短距離,頂点の番号
struct edge{
    int to,cost;
};
int N;
vector<edge> G[MAX]; //
int d[MAX]; //最短距離

void dijkstra(int s){
    priority_queue<P, vector<P>,greater<P> > que;
    
    fill(d,d+N,INF);
    d[s]=0;
    que.push(P(0,s));
    
    while(!que.empty()){
        P p=que.top(); que.pop();
        int v=p.second;
        
        if(d[v] < p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to] =d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    int k,u;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>u>>k;
        for(int j=0;j<k;j++){
            edge e;
            cin>>e.to>>e.cost;
            G[u].push_back(e);
        }
    }
    dijkstra(0);
    for(int i=0;i<N;i++)
        cout<<i<<" "<<(d[i]==INF?-1:d[i])<<"\n";
    
    return 0;
    }
