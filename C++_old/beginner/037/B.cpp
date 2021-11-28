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
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=100000;
static const int NMAX=50;
static const int MMAX=50;
int N,Q,L,R;
ll T;
int main(){
    cin>>N>>Q;
    ll a[N];
    for(int i=0;i<N;i++)a[i]=0;

    for(int i=0;i<Q;i++){
        cin>>L>>R>>T;
        for(int i=L-1;i<=R-1;i++)a[i]=T;
    }

    for(int i=0;i<N;i++){
        cout<<a[i]<<"\n";
    }

    return 0;
}


