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
#define debug(x) cerr << #x << ": " << x << "\n";
#define INF (1<<29) //53687091
#define INFLL (1ll<<58)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N;
ll T,A[MAX+2];

void solve(){
    ll max_delta=-INFLL,cunt=0ll,min_a=INFLL,max_a=-INFLL;
    for(int i=0;i<N;i++){
        min_a = min(min_a,A[i]);
        if(A[i]-min_a > max_delta){
            cunt=1ll;
            max_delta = A[i] - min_a;
        }else if(A[i] - min_a == max_delta) cunt++;
    }
    cout << cunt <<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N >> T;
    for(int i=0;i<N;i++) cin >> A[i];
    solve();
    
    return 0;
}
