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
//#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> P;
map <int,int> mp;
vector<int> V;
list<int> L;
stack<int> S;
queue<int> Q;
deque<int> dq;
#define INF (1<<30)
#define INFLL (1ll<<60)
#define EPS (1e-10)
static const int MAX=1e5;
static const int MOD=1e9+7;
static const int NMAX=50;
static const int MMAX=50;
int W,H;
ll dp[MAX];

//x^n mod m
ll mod_pow(ll x, ll n, ll m) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) {
            res = res * x % m;
        }
        x = x * x % m;
        n >>= 1;
    }
    return res;
}
//mod mのときのxの逆元を求める
ll mod_inv(ll x, ll m) {
    return mod_pow(x, m - 2, m);
}
//nCm mod m mは1e9+7など十分大きな素数にする。
ll mod_comb(ll n, ll k, ll m) {
    ll a = 1, b = 1;
    while(k > 0) {
        a = a * n % m;
        b = b * k % m;
        n--;
        k--;
    }
    return a * mod_inv(b, m) % m;
}

int main(){
    cin.tie(0);  ios::sync_with_stdio(false);
    cin>>W>>H;

    cout<<mod_comb(H+W-2,H-1,MOD)<<"\n";
    
    return 0;
}
