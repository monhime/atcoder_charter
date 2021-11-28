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
#define INFLL (1ll<<50)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=1000;
static const int MMAX=2000;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,M;
typedef struct edge{
    int from,to;
    ll cost;
}Edge;

vector<Edge> V_edge;
ll d[NMAX+2]; //最短距離

//ベルマンフォード法　頂点sからの最短距離を求めるO(NM) エッジの数が多い時はダイクストラ
//後でcheck_nloopで負の閉路が解答に響くか判定
void bellman(int s){
    for(int i=0;i<N;i++) d[i]=INFLL;
    d[s]=0ll;
    
    for(int i=0;i<N-1;i++){ //負の閉路がなければwhile(1)でもN-2回で終わる
        for(int i=0;i<M;i++){
            edge e=V_edge[i];
            
            if(d[e.from]!=INFLL && d[e.to]>d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
            }
        }
    }
}


//負の閉路の影響を受けるノードをnegative[]に記録　影響あればtrue
bool negative[NMAX];
void check_nloop(){
    for(int loop=0;loop<N;loop++){ //全ての頂点の数だけループ
        for(int i=0;i<M;i++){
            edge e=V_edge[i];
            if(d[e.from]==INFLL) continue;  //始点につながってないとこからスタートしてる
            
            if(d[e.to]>d[e.from]+e.cost){ //負の閉路から行けるところはbellmanがおわってもまだ更新できる
                d[e.to]=d[e.from]+e.cost;
                negative[e.to]=true;
            }
        }
        
    }
}

void solve(){
    
    bellman(0);
    
    check_nloop();
    
    if(negative[N-1])cout<<"inf"<<"\n";
    else cout<<(-1)*d[N-1]<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<M;i++){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--; b--;c*=-1; //costの符号を反転し、最小値を求める
        V_edge.push_back((Edge){a,b,c});
    }
    
    solve();
    
    return 0;
}
