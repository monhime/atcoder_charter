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
#define INF 1e6
#define INFLL 1e16
#define EPS (1e-10)
static const int MAX=300;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,M,a[MAX],j,u,v,l;
ll dis[MAX][MAX],ans=INFLL;

//0をに隣接する辺を除いたグラフの全点対最短距離
void floyd(){
    for(int r=1;r<N;r++){
        for(int p=1;p<N;p++){
            for(int q=1;q<N;q++){
                dis[p][q]=min(dis[p][q],dis[p][r]+dis[r][q]);
            }
        }
    }
}

void solve(){
    floyd();
    //頂点1に隣接する頂点のうち、どの異なる2つ(a[i]とa[k])を閉路に含めるか
    for(int i=0;i<j;i++){
        for(int k=0;k<j;k++){
            if(i==k) continue;
            ll aa = dis[0][a[i]] + dis[a[i]][a[k]] + dis[a[k]][0];
            ans = min( aa, ans); //ansを最短距離に更新
        }
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    
    cin>>N>>M;
    for(int i=1;i<N;i++){
        for(int o=1;o<N;o++){
            if(i==o) dis[i][o]=0;
            else dis[i][o]=INFLL;
        }
    }
    
    for(int i=0;i<M;i++){
        cin>>u>>v>>l;
        u--; v--;
        if(!u){
            a[j]=v; j++;
        }else if(!v){
            a[j] = u; j++;
        }
        dis[u][v] = l;
        dis[v][u] = l;
    }
    
    solve();
    
    cout<<(ans==INFLL?-1:ans)<<"\n";
    return 0;
}
