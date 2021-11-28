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
using Pll = pair<ll, ll>;

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
// n^k mod MOD
long long mod_pow(long long n, long long k, long long mod) {
    long long result = 1;
    // k を右シフトしつつ n を 2 乗していく
    while (k > 0) {
        // k の最下ビットが 1 なら、今の n を答えに掛ける
        if ((k & 1) == 1) result = (result * n) % mod;
        n = n * n % mod;
        k >>= 1;
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;

    cin >> n >> k;
    
    cout << mod_pow(n, k, MOD) << "\n";

    return 0;
}