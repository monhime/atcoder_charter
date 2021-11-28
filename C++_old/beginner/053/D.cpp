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
int N,a,cunt,cunt_even;

void solve(){
    for(auto u:mp){
        if(u.second%2)cunt++;
        else cunt_even++;
    }
    
    cout<<cunt + (cunt_even==1?0:cunt_even/2*2)<<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>N;
    for(int i=0;i<N;i++) {
        cin>>a;
        mp[a]++;
    }
    solve();
    
    return 0;
}
