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

struct Comb {
    vector<vector<long long>> com;
    Comb(int MAX_N = 100) { //ありうる最大のn
        com.assign(MAX_N, vector<long long>(MAX_N));
        com[0][0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            com[i][0] = 1;
            for (int j = 1; j < MAX_N; j++) {
                com[i][j] = (com[i - 1][j - 1] + com[i - 1][j]);
            }
        }
    }
    long long nCk(int n, int k) {
        assert(!(n < k));
        assert(!(n < 0 || k < 0));
        return com[n][k];
    }
};


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    Comb comb(100);
    cout << comb.nCk(n, 4) << "\n";

    return 0;
}