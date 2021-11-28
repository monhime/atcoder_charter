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
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int N,K;
vector<int> x,y; //入力
vector<int> xx,yy; //位置がソートされる
void solve(){
    ll ans=1ll*(xx[N-1]-xx[0])*(yy[N-1]-yy[0]);
    
    for(int xi=0;xi<N;xi++){
        for(int xj=xi+1;xj<N;xj++){
            for(int yi=0;yi<N;yi++){
                for(int yj=yi+1;yj<N;yj++){
                    int lx=xx[xi],rx=xx[xj]; //左、右
                    int by=yy[yi],uy=yy[yj]; //下、上
                    
                    int num=0;
                    for(int i=0;i<N;i++){
                        if(lx<=x[i]&&x[i]<=rx
                           &&by<=y[i]&&y[i]<=uy) num++;
                    }
                    if(num>=K)
                        ans=min(ans,1ll*(rx-lx)*(uy-by));
                }
            }
        }
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>K;
    
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        x.push_back(a); y.push_back(b);
        xx.push_back(x[i]); yy.push_back(y[i]);
    }
    
    sort(xx.begin(),xx.end());
    sort(yy.begin(),yy.end());

    
    cout<<ans<<"\n";
    
    
    
    return 0;
}
