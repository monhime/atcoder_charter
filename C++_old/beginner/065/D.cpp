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
#define debug(x) cerr << #x << ": " << x << "\n";
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=(int) 1e6;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };

struct node{
    int x,y,id;
}a[MAX];
struct edge{
    int u,v,wt;
    bool operator < (const edge &e) const{
        return wt<e.wt; //重みが昇順になるように
    }
}g[MAX];

bool cmpx(node a,node b) { return a.x < b.x; }
bool cmpy(node a,node b) { return a.y < b.y; }

//-------------UnionFind--------------------
//MAX
int par[MAX]; //親
int un_rank[MAX]; //木の深さ
//int united[MAX];
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i; //un_rank[i] = 0; //必要なし
        //united[i] = 1;
    }
}
int find(int x){
    //xが木の根ならそれを、そうでないなら根を記録しながら木の根を返す
    return x==par[x] ? x : par[x] = find(par[x]);
}
bool same(int x,int y){
    //xとyが同じ集合に属するか
    return find(x) == find(y);
}
//xとyの属する集合を併合
void unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return;
    
    if(un_rank[x] < un_rank[y]){
        par[x] = y;
        //united[y] += united[x];
    }else{
        par[y] = x;
        //united[x] += united[y];
        if(un_rank[x] == un_rank[y]) un_rank[x]++;
    }
}
/*
int count(int x){
    return united[find(x)];
}
 */
//------------------------------------------


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    int N,m = 0;
    ll res = 0ll;
    cin >> N;
    
    for(int i=0;i<N;i++){
        par[i]=i;
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    
    sort(a,a+N,cmpx); //x座標でソート
    for(int i=0;i<N-1;i++) g[m++] = (edge){a[i].id, a[i+1].id, a[i+1].x-a[i].x};
    sort(a,a+N,cmpy);
    for(int i=0;i<N-1;i++) g[m++] = (edge){a[i].id, a[i+1].id, a[i+1].y-a[i].y};
    sort(g,g+m);
    
    for(int i=0;i<m;i++){
        if(!same(g[i].u,g[i].v)){ //g[i]をつないでも閉路ができない
            res += g[i].wt; //コストを加算
            unite(g[i].u,g[i].v);
        }
    }
    
    cout << res << "\n";
    return 0;
}
