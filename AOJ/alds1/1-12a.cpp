#include<iostream>
using namespace std;
static const int MAX=100;
static const int INFTY=2000000000;
static const int WHITE=0;
static const int GRAY=1;
static const int BLACK=2;

int n,M[MAX+1][MAX+1];
int prim(){
    int u,minv;
    int d[MAX+1],p[MAX+1],color[MAX+1];
    for(int i=1;i<=n;i++){
        d[i]=INFTY;
        p[i]=-1;
        color[i]=WHITE;
    }
    d[1]=0;
    while(1){
        minv=INFTY;
        u=-1;
        for(int i=1;i<=n;i++){
            if(minv>d[i]&&color[i]!=BLACK){
                u=i;
                minv=d[i];
            }
        }
        if(u==-1)break;
        color[u]=BLACK;
        for(int v=1;v<=n;v++){
            if(color[v]!=BLACK&&M[u][v]!=INFTY){
                if(d[v]>M[u][v]){
                    d[v]=M[u][v];
                    p[v]=u;
                    color[v]=GRAY;
                }
            }
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(p[i]!=-1) sum+=M[i][p[i]];
    }
    return sum;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int e;
            cin>>e;
            M[i][j]=(e==-1)?INFTY:e;
        }
    }
    cout<<prim()<<"\n";
    return 0;
}
