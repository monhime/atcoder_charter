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
map <pair<int,int>,int> mp;
vector<int> V;
#define debug(x) cerr << #x << ": " << x << "\n";
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
int tx[9] = { 1,1,1,0,0,0,-1,-1,-1 }, ty[9] = { -1,0,1,-1,0,1,-1,0,1 };
ll H,W,a[MAX+2],b[MAX+2],cunt[10];
int N;
vector<P>  square;

void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<9;j++){
            int x,y;
            x=a[i]+tx[j];
            y=b[i]+ty[j];
            if(x<=0 || x >=H-1 || y <=0 || y >= W-1) continue;
            
            mp[P(x,y)]++;
        }
    }
    for(auto p:mp) cunt[p.second]++;
    
    cout<< (H-2)*(W-2)*1ll-mp.size() <<"\n";
    for(int i=1;i<10;i++) cout<<cunt[i]<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> H >> W >> N;
    for(int i=0;i<N;i++) {cin >> a[i] >>b[i]; a[i]--; b[i]--;}
    solve();
    
    return 0;
}
