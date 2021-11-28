#define _GLIBCXX_DEBUG
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
using vi = vector<int>;
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

template <class T>
vector<T> make_divisors(T n) {
    vector<T> res;
    for (T i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (n/i != i) res.emplace_back(n/i);
        }
    }
    sort(ALL(res));
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    
    long long N;
    cin >> N;
    for (const auto &res: make_divisors(N)) 
        cout << res << " ";
    cout << endl;

    return 0;
}
