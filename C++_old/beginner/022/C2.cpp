#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<map>
#include<functional>
#include<queue>
#include<stack>
#include<string.h>
#define ll long long int
#define MOD 1000000007LL
static const int INF =1e9;
using namespace std;
//ワーシャルフロイド法

int main() {
    ll dis[500][500]={};
    int n,m;
    cin>>n>>m;
    int a[500]={};
    //異なる点間の距離をINFに。0からは、0と隣接する点と、隣接しない点でそれぞれ後で代入
    for(int i=1;i<=n;i++){
        for(int o=1;o<=n;o++){
            if(i==o){
                dis[i][o]=0;
            }else{
                dis[i][o]=INF;
            }
        }
    }
    
    int j=0;
    for(int i=0;i<m;i++){
        int u,v,l;
        cin>>u>>v>>l;
        u--;
        v--;
        if(u==0){ //0→v
            a[j]=v; //0に隣接するリストを作る。双方向なので、被らない。
            j++;
        }else if(v==0){
            a[j]=u;
            j++;
        }
        dis[u][v]=l;
        dis[v][u]=l;
        
    }
    
    //ワーシャルフロイド法でp→qの最短距離を求める
    for(int r=1;r<n;r++){
        for(int p=1;p<n;p++){
            for(int q=1;q<n;q++){
                dis[p][q]=min(dis[p][q],dis[p][r]+dis[r][q]);
            }
        }
    }
    ll ans=INF;
    for(int i=0;i<j;i++){
        for(int k=0;k<j;k++){
            if(i!=k){
                ll aa=dis[0][a[i]]+dis[a[i]][a[k]]+dis[a[k]][0];
                ans=min(aa,ans); //ansを最短距離に更新
            }
        }
    }
    cout<<(ans==INF?-1:ans)<<"\n";
}
