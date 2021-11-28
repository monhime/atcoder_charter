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
int N,M,p[MAX+2],x[MAX+2],y[MAX+2];

//------------Union find---------------
class UnionFind{
    int par[MAX+2],rank[MAX+2];
public:
    //n要素で初期化
    UnionFind(int n){
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
    }
    //木の根を求める
    int find(int x){
        if(par[x]==x) return x;
        else return par[x] = find(par[x]);
    }

    //xとyの属する集合を併合
    void unite(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y) return ;
    
        if(rank[x]<rank[y]) par[x]=y;
        else{
            par[y]=x;
            if(rank[x]) rank[x]++;
        }
    }

    //xとyが同じ集合に属するか
    bool same(int x,int y){
        return find(x)==find(y);
    }
};

void solve(){
    UnionFind un(N);
    for(int i=0;i<M;i++) un.unite(x[i],y[i]);
    int cunt=0;
    for(int i=1;i<=N;i++){
        if(un.same(i,p[i-1])) cunt++;
    }
    cout<<cunt<<"\n";
}


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>p[i];
    for(int i=0;i<M;i++) cin>>x[i]>>y[i];
    
    solve();
    
    
    return 0;
}
