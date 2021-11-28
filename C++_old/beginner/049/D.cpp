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
#include<utility>
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
static const int MAX= (int)2e5+2;
static const int MOD= (int)1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,K,L,a[MAX],b[MAX];
vector<P> ls;

template <size_t N>
class unionFindTree{
    int par[N],rank[N],united[N];
public:
    unionFindTree(){
        for(int i = 0; i < (int) N; i++){
            par[i] = i; rank[i] = 0; united[i] = 1;
        }
    }
    void init(){
        for(int i = 0; i < (int) N; i++){
            par[i] = i; rank[i] = 0; united[i] = 1;
        }
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x, int y){
        x = find(x); y = find(y);
        if(x == y) return;
        
        if(rank[x] < rank[y]){
            par[x] = y;
            united[y] += united[x];
        }else{
            par[y] = x;
            united[x] += united[y];
            if(rank[x] == rank[y]) rank[x]++;
        }
    }
    bool same(int x, int y){
        return find(x) == find(y);
    }
    int count(int x){
        return united[find(x)];
    }
};


 void solve(){
     unionFindTree<MAX> un_a,un_b;
     
     for(int i=0;i<K;i++) un_a.unite(a[i],b[i]);
     for(int i=K;i<K+L;i++) un_b.unite(a[i],b[i]);
  
     for(int i=0;i<N;i++) ls.push_back(make_pair(un_a.find(i),un_b.find(i)));
     
     sort(ls.begin(),ls.end());
     
     for(int i=0;i<=N-1;i++){
         cout<<upper_bound(ls.begin(),ls.end(),make_pair(un_a.find(i),un_b.find(i)))
         -lower_bound(ls.begin(),ls.end(),make_pair(un_a.find(i),un_b.find(i)))
         <<(i==N-1?"\n":" ");
    }
     
 }


int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N>>K>>L;
    for(int i=0;i<K;i++) {cin>>a[i]>>b[i]; a[i]--; b[i]--;}
    for(int i=K;i<K+L;i++) {cin>>a[i]>>b[i]; a[i]--; b[i]--;}
    solve();
    
    return 0;
}
