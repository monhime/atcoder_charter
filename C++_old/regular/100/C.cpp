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

ll A[2*MAX+2],m1,a,m2,M,N,sum;



void solve(){
    sort(A,A+N);
    if((N+1)%2) M = A[(N+1)/2];
    else M = A[(N+1)/2-1];
    for(int i=0;i<N;i++){
        sum += abs(A[i] - M);
    }
    cout << sum << "\n";
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin >> N;
    for(ll i=0ll;i<N;i++){
        cin >> a;
        A[i] = a - ( i + 1ll ); //A[i] = A[i]-i
    }
    solve();
    
    return 0;
}

