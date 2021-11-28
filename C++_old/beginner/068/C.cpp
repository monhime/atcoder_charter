#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
static const int MAX=200000;

bool graph[MAX][MAX],visited[MAX],pos;

int main(){
    ll cunt,N,M,a,b; //N:島の個数,M:船の数
    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>a>>b;
        a--;b--;
        graph[a][b]=graph[b][a]=true;
    }
   
    for(int v=1;v<N-1;v++){
        if(graph[0][v]&&graph[v][N-1])
            pos=true;
            break;
    }

    cout<<(pos?"POSSIBLE":"IMPOSSIBLE")<<"\n";
    
    return 0;
}

