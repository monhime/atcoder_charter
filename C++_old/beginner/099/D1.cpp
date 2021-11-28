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
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,C,X,D[32][32],t[3][32]; //i+j mod 3=iの場所に色jがt[i][j]個

void solve(){
    int ans=INF;
    //C種類から3つ選ぶ組み合わせを総あたり
    for(int i=1;i<=C;i++){
        for(int j=1;j<=C;j++){
            if(i!=j){
                for(int k=1;k<=C;k++){
                    if(i!=k&&j!=k){
                        int tt=0;
                        for(int l=1;l<=C;l++) tt+=D[l][i]*t[0][l];
                        for(int l=1;l<=C;l++) tt+=D[l][j]*t[1][l];
                        for(int l=1;l<=C;l++) tt+=D[l][k]*t[2][l];
                        
                        ans=min(ans,tt);
                     }
                }
            }
        }
    }
    cout<<ans<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >>N>>C;
    for(int i=1;i<=C;i++){
        for(int j=1;j<=C;j++){
            cin>>D[i][j];
        }
    }
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>X;
            t[(i+j)%3][X]++;
        }
    }
        
    solve();
    
    return 0;
}
