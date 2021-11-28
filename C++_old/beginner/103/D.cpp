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
static const int MAX=(int) 1e5;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int dx[4]={0,1,0,-1},dy[4]={-1,0,1,0};
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
int N,M,a,b,cunt,max_bridge=-1;
P A[MAX+2];

bool comp(P l,P r){
    if(l.second != r.second) return l.second < r.second;
    return l.first  < r.first;
}

void solve(){
    sort(A,A+M,comp);
    for(int i=0;i<M;i++){
        if(A[i].first > max_bridge){
            max_bridge = A[i].second - 1;
            cunt++;
        }
    }
    cout << cunt <<"\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        cin >> a >> b;
        A[i] = make_pair(a,b);
    }
    solve();
    
    return 0;
}

