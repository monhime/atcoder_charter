#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
static const int NMAX=8;
static const int MMAX=28;

bool graph[NMAX][NMAX],visited[NMAX];
int a[MMAX],b[MMAX];
int n,m,cunt;
int  dfs(int v){
    visited[v]=true;

    bool flag=true;
    
    for(int v=0;v<n;v++){
        if(visited[v])continue;
        else flag=false;
    }
    
    if(flag)cunt++;
    
    for(int v2=0;v2<n;v2++){
        if(!graph[v][v2])continue;
        if(visited[v2])continue;
        
        dfs(v2);
        
        visited[v2]=false;
    }
    return cunt;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        
        a[i]--;b[i]--;
        graph[a[i]][b[i]]=graph[b[i]][a[i]]
            =true;
    }

    cout<<dfs(0)<<"\n";    
    

    return 0;
}

