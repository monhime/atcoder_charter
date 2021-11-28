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
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,a,b;

typedef pair<int, int> P; //最短距離,頂点の番号
struct edge{
    int to,cost;
};
vector<edge> G[MAX+2];
int d1[MAX+2]; //1からの最短距離
void dijkstra1(){
    int s=1;
    priority_queue<P, vector<P>,greater<P> > que; //(<距離、座標>、照準)
    fill(d1,d1+N+1,INF);
    d1[s]=0; //スタート地点
    que.push(P(0,s));
    
    while(!que.empty()){
        P p=que.top(); que.pop(); //すでに更新した中で一番sから近いとこ
        int v=p.second;
        if(d1[v] < p.first) continue; //その場所の距離が前の記録より大きい時
        for(auto u:G[v]){
            if(d1[u.to]>d1[v]+u.cost){
                d1[u.to] =d1[v]+u.cost; //更新
                que.push(P(d1[u.to],u.to)); //更新したとこを記録
            }
        }
    }
}

int d2[MAX+2]; //1からの最短距離
void dijkstra2(){
    int s=N;
    priority_queue<P, vector<P>,greater<P> > que; //(<距離、座標>、照準)
    fill(d2,d2+N+1,INF);
    d2[s]=0; //スタート地点
    que.push(P(0,s));
    
    while(!que.empty()){
        P p=que.top(); que.pop(); //すでに更新した中で一番sから近いとこ
        int v=p.second;
        if(d2[v] < p.first) continue; //その場所の距離が前の記録より大きい時
        for(auto u:G[v]){
            if(d2[u.to]>d2[v]+u.cost){
                d2[u.to] =d2[v]+u.cost; //更新
                que.push(P(d2[u.to],u.to)); //更新したとこを記録
            }
        }
    }
}


void solve(){
    dijkstra1();
    dijkstra2();
    int cunt1=0;
    for(int i=1;i<=N;i++){
        if(d1[i]<=d2[i]) cunt1++;
    }
    if(cunt1>N/2)cout<<"Fennec"<<"\n";
    else cout<<"Snuke"<<"\n";
    /*
    for(int i=1;i<=N;i++){
        cout<<d1[i]<<" "<<d2[i]<<"\n";
    }*/
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N-1;i++){
        cin>>a>>b;
        G[a].push_back((edge){b,1});
        G[b].push_back((edge){a,1});
    }
    solve();
    
    return 0;
}
