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
vector<int> V;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=100;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
// {この頂点への最短距離, この頂点の番号} を管理する構造体
struct P {
    int dist, num;
    // デフォルト(大きい値が先頭)
    bool operator<(const P &p) const {
        return dist < p.dist;
    }
    // greater(小さい値が先頭)
    bool operator>(const P &p) const {
        return dist > p.dist;
    }
};

vector<vector<int> > G;
int N,a,b,M,dist[NMAX+2]; //aからiまでの最短距離
ll cunt[NMAX+2]; //aからiまでの最短距離で来る経路数

//重み1なので、遅くついたほうが早いことは無い。
void dijkstra(int s){

    fill(dist,dist+N,INF);
    dist[s]=0;
    priority_queue<P, vector<P>,greater<P> > Q;
    
    P p;
    p.dist=0; p.num=s;
    Q.push(p);
    cunt[s]=1; //起点へ向かう経路数は1
    
    while(!Q.empty()){
        P p=Q.top(); Q.pop();
        int v=p.num; //今見ている頂点
        
        if(dist[v]<p.dist) continue; //最短距離ではない
        //二回目にtについた時は、tへの距離はd[t](!=INF)か、それより大きい
        for(int t:G[v]){ //vからつながってる先をループ
            if(dist[t]> dist[v]+1){ //tへの最短距離がvのそれ+1ならtは最短経路上にある。(INFのときだけ?)
                dist[t]=dist[v]+1;
                P p;
                p.dist=dist[t]; p.num=t;
                Q.push(p);  //tの情報をQに追加
            }
            // 今見ている頂点が最短経路上にあるならば、前の頂点からのカウントを足し合わせる
            if(dist[t]==dist[v]+1)
                cunt[t] += cunt[v]; //tへの経路数にvへの経路数を加える
        }
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>a>>b>>M;
    a--; b--;
    G= vector<vector<int> >(N);
    for(int i=0;i<M;i++){
        int x,y;
        
        cin>>x>>y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    dijkstra(a);
    
    cout<<cunt[b]%MOD<<"\n";
    
    return 0;
}
