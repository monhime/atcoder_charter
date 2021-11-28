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
int a,b,ans;

void solve(){
    ans =1;
    for(int i=0;i<a;i++) ans*=100;
    if(b!=100)ans*=b;
    else ans *= 101;
    cout<<ans <<"\n";
}

int main(){
    cin >> a >> b;
    solve();
    return 0;
}
