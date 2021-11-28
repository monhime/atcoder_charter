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
static const int MAX=10000;
static const int NMAX=50;
static const int MMAX=50;
ll a[MAX+1];
int N;

//xの約数kの個数
int count_divisor(ll x,ll k){
    int cunt=0;
    while(x){
        if(x%k) return cunt;
        x /= k; cunt++;
    }
}

void solve(){
    int ans = 0;
    for(int i = 0;i < N; i++) ans += count_divisor(a[i],2);
    cout << ans << "\n";
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    solve();
    return 0;
}
