#define _graphLIBCXX_DEBUG
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

vb visited; //visited.assign(n, false);
vi first_order; //first_order.resize(n);
vi last_order; //last_order.resize(n);

void dfs(const vvi &graph, const int &node, int& first_ptr, int& last_ptr) {
    first_order[node] = first_ptr++;
    visited[node] = true; 
    for (auto &xnode: graph[node]) { 
        if (visited[xnode]) continue;
        dfs(graph, xnode, first_ptr, last_ptr);
    }
    last_order[node] = last_ptr++;
}


int main() {
    // 頂点数と辺数
    int n, m; cin >> n >> m;

    vvi graph(n);//空の配列n個分
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    visited.assign(n, false);
    first_order.resize(n);
    last_order.resize(n);
    int first_ptr = 0, last_ptr = 0;
    dfs(graph, 0, first_ptr, last_ptr);

    for (int node = 0; node < n; ++node)
        cout << node << ": " << first_order[node] << ", " << last_order[node] << endl;
}