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
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,D[32][32],c[502][502],C,D1[32][3];

void initialize(){
    for(int i=1;i<=C;i++){
        for(int mod=0;mod<3;mod++){
            int min_D=INF;
            for(int j=1;j<=C;j++){
                if(j%3==mod && j!=i) min_D=min(min_D,D[i][j]);
            }
            D1[i][mod] = min_D;
        }
    }
}

void solve(){
    //iからmod3が同じ他の数に塗り替える時の最小値の配列をつくる
    initialize();
    int ans=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if((i+j)%3 != c[i][j]%3){
                ans+=D1[c[i][j]][(i+j)%3];
                cout<<D1[c[i][j]][(i+j)%3]<<" ";
            }
            
        }
        cout <<"\n";
    }
    cout << ans <<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>C;
    for(int i=1;i<=C;i++){
        for(int j=1;j<=C;j++) cin>>D[i][j];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++) cin>>c[i][j];
    }
    solve();
    
    for(int i=1;i<=C;i++){
        for(int j=0;j<3;j++) cout<< D1[i][j] <<" ";
        cout <<"\n";
    }
    return 0;
}
