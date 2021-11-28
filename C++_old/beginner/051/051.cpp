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
static const int MAX=1e3;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,M,a[MAX+2],b[MAX+2],c[MAX+2],dist[100][100];

void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j) dist[i][j]=0;
            else dist[i][j]=INF;
        }
    }
    for(int i=0;i<M;i++){
        dist[a[i]][b[i]]=min(dist[a[i]][b[i]],c[i]);
        dist[b[i]][a[i]]=min(dist[b[i]][a[i]],c[i]);
    }
    //ワーシャルフロイド
    for(int k=0;k<N;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
        }
    }
    int ans = M; //最短経路に含まれていない辺の数
    for(int i=0;i<M;i++){
        bool shortest = false;
        for(int j=0;j<N;j++){
            if(dist[j][a[i]]+c[i]==dist[j][b[i]]) shortest=true;
        }
        if(shortest) ans--;
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--; b[i]--;
    }
    solve();
    
    return 0;
}
