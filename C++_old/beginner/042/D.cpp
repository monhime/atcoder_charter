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
static const int MAX=(int) 25e4;
static const int MOD=(int) 1e9+7;
static const int NMAX=50;
static const int MMAX=50;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
using namespace std;
ll fact[MAX+2], fact_inv[MAX+2];
// n^r mod p   O(logn)
ll pow_mod(ll n, ll r, ll p){
    if (r == 0) return 1;
    if (r % 2 == 0) //n^r ≡ (n ^2) ^r/2 ≡ (n*n%p)^r/2 mod p
        return pow_mod(n*n%p , r/2, p) % p;
    else //n ^r ≡ n ^r-1 *n ≡ (n ^r-1 mod p) * n mod p
        return n * pow_mod(n, r-1, p) % p;
}
//n! mod p とその逆元までを予め配列に入れとく
void factorial(ll n, ll p){
    fact[0] = 1;
    fact[1] = 1;
    for(int i=2;i<n+1;i++) fact[i] = i * fact[i-1] % p; //階乗 mod p の配列
    fact_inv[n] = pow_mod(fact[n], p-2, p);
    for(int i=n-1; i>=0; --i) fact_inv[i] = fact_inv[i+1] * (i+1) % p;
}

ll comb(ll n, ll r, ll p){
    // nCr mod p
    if (n < 0 || r < 0 || r > n) return 0;
    return (fact[n] * fact_inv[r] % p) * fact_inv[n-r] % p;
}

int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    factorial(MAX, MOD);
    ll ans = 0ll;
    for(int i=0;i< h-a;i++){
        ans += comb((b-1+i), i, MOD) * comb(h-1-i+(w-b-1), w-b-1, MOD) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}
