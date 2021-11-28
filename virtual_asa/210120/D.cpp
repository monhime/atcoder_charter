#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pill = pair<int, ll>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

template <class T>
bool chmax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

struct Mod_comb {
    vector<long long> fact, factinv, inv;
    Mod_comb(int n = 100000) {
        fact.resize(n + 1);
        factinv.resize(n + 1);
        inv.resize(n + 1);
        fact[0] = fact[1] = 1;
        factinv[0] = factinv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; ++i) {
            fact[i] = fact[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            factinv[i] = factinv[i - 1] * inv[i] % MOD;
        }
    }
    long long C(int n, int r) {
        if (n < r || n < 0 || r < 0) {
            return 0;
        } else {
            return fact[n] * (factinv[r] * factinv[n - r] % MOD) % MOD;
        }
    }
    long long P(int n, int r) {
        if (n < r || n < 0 || r < 0) {
            return 0;
        } else {
            return fact[n] * factinv[n - r] % MOD;
        }
    }
    long long H(int n, int r) { return C(n + r - 1, r); }
};

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y; cin >> x >> y;
    if ((x + y) % 3 == 0 && x >= (x + y)/3 && y >= (x + y)/3){
        
        int nn = (x + y) / 3;
        Mod_comb mod_comb(nn);
        cout << mod_comb.C(nn, x - nn) << "\n";
    }
    else    cout << 0 << "\n";
    return 0;
}
