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
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,M,R;
int d[201][201];
int r[9];
int A,B,C;
int res;
bool used [9];

void floyd(){
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(d[i][j]>d[i][k]+d[k][j]) d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
}
//R!の順列を表現
void dfs(int c,int las,int dist) { //c:何回目,las:今の場所,dist:今の距離
    if(c==R+1) {
        res=min(res,dist);
        return;
    }
    for(int i=1;i<=R;i++)if(!used[i]) {
        used[i]=true;
        if(las==-1)dfs(c+1,i,0);
        else dfs(c+1,i,dist+d[r[las]][r[i]]);
        used[i]=false;
    }
}

void solve(){
    floyd();
    
    res=INF;
    dfs(1,-1,0);
}

int main () {
    cin>>N>>M>>R;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i!=j)d[i][j]=INF;
        }
    }
    for(int i=1;i<=R;i++)cin>>r[i];
    
    for(int i=1;i<=M;i++){
        cin>>A>>B>>C;
        d[A][B]=d[B][A]=C;
    }
    
    solve();
    
    cout<<res<<"\n";
}
