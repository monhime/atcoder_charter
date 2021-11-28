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
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int H,W;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>H>>W;
    bool cc[H+2][W+2];
    memset(cc,0,sizeof(cc));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            char c;
            cin>>c;
            if(c=='#')cc[i][j]=true;
        }
    }
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            if(cc[i][j]){
                bool flag=false;
                for(int k=0;k<4;k++){
                    if(cc[i+dx[k]][j+dy[k]])flag=true;
                }
                if(!flag){
                    cout<<"No"<<"\n";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes"<<"\n";
    return 0;
}
