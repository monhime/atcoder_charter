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

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    REP(i, h) cin >> A[i];

    vvi Table(h, vi(w, 100000));//llなら0ll
    REP(i, h)REP(j, w){
        if (A[i][j] == '#') Table[i][j] = 0;
    } 
    REP(i, h){
        FOR(j, 1, w){
            chmin(Table[i][j], Table[i][j - 1] + 1);
        }
    }
    REP(i, h){
        for (int j = w - 2; j >= 0; j--){
            chmin(Table[i][j], Table[i][j + 1] + 1);
        }
    }
    REP(j, w){
        FOR(i, 1, h){
            chmin(Table[i][j], Table[i - 1][j] + 1);
        }
    }
    REP(j, w){
        for (int i = h - 2; i >= 0; i--){
            chmin(Table[i][j], Table[i + 1][j] + 1);
        }
    }
    int ans = 0;
    REP(i, h)REP(j, w) chmax(ans, Table[i][j]);
    cout << ans << "\n";
    return 0;
}
