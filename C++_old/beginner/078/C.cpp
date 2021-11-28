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
using namespace std;
map <int,int> mp;
typedef pair<int, int> P;
typedef long long ll;
static const int MAX=100000;
int N,M;

int main(){
    cin>>N>>M;

    ll b=1;

    for(int i=0;i<M;i++)b*=2;
    
    ll ans=(100*N+1800*M)*b;

    cout<<ans<<"\n";
    return 0;
}
