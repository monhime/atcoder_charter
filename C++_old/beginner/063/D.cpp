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
static const ll HMAX=1e9;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,A,B;
ll h[MAX+2];

bool f(ll x){
    ll cunt=0ll;
    for(int i=0;i<N;i++){
        if(h[i]>B*x)
            cunt+=((h[i]-B*x) % (A-B) ? (h[i]-B*x) / (A-B) +1ll:(h[i]-B*x) / (A-B));
    }
    return cunt <= x;
}

/*整数~整数
 l:範囲最小値,r:範囲最大値
 x<rでf=false,x>=rでtrue
 */
ll binary_search2(ll l,ll r){
    while(r-l>1ll){ //r=l+1になるまで
        ll m=(l+r)/2ll; //平均値かその左の整数
        if(f(m))r=m; //カッコ内の条件式は任意
        else l=m; //解x>m
    }
    return r;
}

void solve(){
    cout<<binary_search2(0ll,HMAX)<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N>>A>>B;
    for(int i=0;i<N;i++) cin>>h[i];
    solve();
    
    return 0;
}
