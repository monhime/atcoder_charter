#include <numeric>
#include<iostream>
#include<set>
#include<queue>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#include <sstream>
#include<string>
#include <cmath>
#include <iomanip>
#include <string>
#include<list>
#include<string.h>
#include<memory.h>
using namespace std;
#define inf 1000000007
#define int long long
#define rep(i,j,n) for(int i=j;i<n;i++)
typedef pair<int,int>  P;
double pi = 3.141592653589793;
//ここから下
struct edge{int to,cost;};
vector<edge> G[500];
int d[500];
int v,e;
void dijkstra(int k){
    priority_queue<P,vector<P>,greater<P> >que;
    while(!que.empty())que.pop();
    d[k]=0;
    que.push(P(0,k));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size(); i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
signed main(){
    cin>>v>>e;vector<edge> sp;
    rep(i,0,e){
        int a,b,c;cin>>a>>b>>c;
        if(a==1||b==1){
            if(a==1)sp.push_back(make_pair(b-1,c));
            else sp.push_back(edge(a-1,c);
        }
        else {
            G[a-1].push_back(edge(b-1,c));
            G[b-1].push_back(edge(a-1,c));
        }
    }
    int ans=inf;
    rep(i,0,sp.size()){
        fill(d,d+500,inf);
        dijkstra(sp[i].to);
        rep(j,i+1,sp.size()){
            ans=min(ans,d[sp[j].to]+sp[i].cost+sp[j].cost);
        }
    }
    if(ans==inf)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}
