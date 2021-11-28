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
static const int MAX=1e4;
static const int MOD=1e9+7;
static const int HMAX=100;
static const int WMAX=100;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int H,W,N,a[MAX+2],x,cuntx,cunty;
int c[HMAX+2][WMAX+2];

//priority_queue<P, vector<P>,greater<P> > que;//<使用回数,色>,昇順


void solve(){
    cuntx=1;cunty=1;
    for(int i=1;i<=N;i++){ //色iについて
        while(a[i]){
            c[cuntx][cunty]=i;
            if(cunty % 2){ //偶数列は下へ
                if(cuntx==H) cunty++;
                else cuntx++;
            }else{ //奇数列は上へ
                if(cuntx==1) cunty++;
                else cuntx--;
            }
            a[i]--;
        }
    }
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>H>>W>>N;
    for(int i=1;i<=N;i++) {
        cin>>a[i];
    }
    solve();
    
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++) cout<<c[i][j]<<" ";
        cout<<"\n";
    }
    return 0;
}
