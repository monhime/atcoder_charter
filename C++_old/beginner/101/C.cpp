#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
//#include <bits/stdc++.h>
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int N,K;

void solve(){
    if(N!=K)
        cout<< ((N-1)%(K-1) ? (N-1)/(K-1)+1 : (N-1)/(K-1)) <<"\n";
    else
        cout<<1<<"\n";
}

int main(){
    cin>>N>>K;
    int a[N];
    for(int i=0;i<N;i++)cin>>a[i];
    solve();
    return 0;
}
