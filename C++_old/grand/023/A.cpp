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
map <ll,ll> mp;
vector<int> V;
#define debug(x) cerr << #x << ": " << x << "\n";
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=(int) 2e5;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N;
ll a,ans,sum;
vector<ll> S;
void solve(){
    sort(S.begin(),S.end());
    S.erase(unique(S.begin(),S.end()),S.end());
    for(int i=0;i<S.size();i++){
        ans = (mp[S[i]] - 1)* mp[S[i]] /2;
    }
    cout << ans <<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N;
    S.push_back(0ll);
    mp[0]=1;
    for(int i=1;i<=N;i++) {
        cin >>a;
        sum += a;
        S.push_back(sum);
        mp[sum]++;
    }
    solve();
    
    return 0;
}
