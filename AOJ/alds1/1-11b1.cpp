#include<iostream>
#include<cstdio>
using namespace std;
static const int N=100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
int n,M[N+1][N+1];
int color[N+1],d[N+1],f[N],tt;
int nt[N+1];
void dfs_visit(int r){

}
void dfs(){
    for(int u=1;u<=n;u++){
        
    color[u]=WHITE;
    nt[i]=0;
    }
    tt=0;
    for(int u=1;u<=n;u++){
        if(color[u]==WHITE)dfs_visit(u);
    }
    for(int u=1;u<=n;u++)
        cout<<u<<" "<<d[u]<<" "<<f[u]<<"\n";
}
int main(){
    int u,v,k;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            M[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        cin>>u>>k;
        for(int j=1;j<=k;j++){
            cin>>v;
            M[u][v]=1;
            
        }
    }
    dfs();
    return 0;
}


