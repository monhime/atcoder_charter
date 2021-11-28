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

int main() {
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    vvi graph(n);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    queue<int> que;
    que.emplace(0);
    vector<bool> visited(n); //-1は未訪問
    visited[0] = true;
    vi ans(n, 0);
    while (!que.empty()) {
        int node = que.front(); que.pop();
        for (auto &xnode : graph[node]) {
            if (visited[xnode]) {
                continue;
            }
            visited[xnode] = true;
            ans[xnode] = ans[node] + 1;
            que.emplace(xnode);
        }
    }
    REP(v, n) cout << v << ": " << ans[v] << endl;
    return 0;
}