#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<stack>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
typedef long long ll;
#define INF (1<<30)
#define INFLL (1ll<<60)

using namespace std;
static const int MAX=50;
int n,m;
int a[MAX],b[MAX];
bool graph[MAX][MAX];
bool visited[MAX];

/*void dfs(int v){
  visited[v]=true;//vからスタート
  for(int v2=0;v2<n;v2++){
  if(!graph[v][v2])continue;
  if(visited[v2])continue;
  dfs(v2);
  }
  } */

void dfs(int v){
    stack<int> S;
    S.push(v);
    visited[v]=true;
    while(!S.empty()){
        int v2=S.top();S.pop();
        for(int i=0;i<n;i++){
            if(!graph[v2][i])continue;
            if(visited[i])continue;
            visited[i]=true;
            S.push(i);//スタックに追加
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){//隣接リスト表現→隣接行列
        cin>>a[i]>>b[i];

        a[i]--;b[i]--;
        graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;
    }
    int ans=0;
    for(int i=0;i<m;i++){
        graph[a[i]][b[i]]=graph[b[i]][a[i]]=false;
        for(int j=0;j<n;j++)visited[j]=false;

        dfs(0);//iを抜いてみて探索

        bool bridge=false;
        for(int j=0;j<n;j++){
            if(!visited[j])bridge=true;
        }
        if(bridge)ans+=1;

        graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;//元に戻す
    }
    cout<<ans<<"\n";
    return 0;
}
