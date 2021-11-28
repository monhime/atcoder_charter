#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
//#include <bits/stdc++.h>
static const int INF=100000;
using namespace std;
int d[50][50];
typedef pair<int, int> P;

int H,W;
char s[51][51];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

void bfs(){
    queue<P> q;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            d[i][j]=INF;
        }
    }
    q.push(P(0,0));
    d[0][0]=1;
    while(!q.empty()){
        P u=q.front();q.pop();
        for(int i=0;i<4;i++){
            s[u.first][u.second]=0;
            int nx=u.first+dx[i];
            int ny=u.second+dy[i];
            if(0<=nx&&nx<H&&0<=ny&&ny<W
                &&s[nx][ny]=='.'&&d[nx][ny]==INF){
                q.push(P(nx,ny));
                d[nx][ny]=d[u.first][u.second]+1;
            }
        }    
    }                            
}
int main(){
    scanf("%d %d",&H,&W);
    char c;
    int cunt2=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin>>c;
            if(c=='#')cunt2++;
            s[i][j]=c;
        }    
    }
    bfs();
    if(d[H-1][W-1]==INF){
        cout<<-1<<"\n";
        return 0;
    }
    int ans=H*W-d[H-1][W-1]-cunt2;;
    cout<< ans<<"\n"; 
    return 0;
}
