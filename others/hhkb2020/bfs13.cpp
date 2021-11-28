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
constexpr int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

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

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    vvi graph(n);
    REP(i, n - 1) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> que;
    que.push(0);
    vi depth(n, -1); //-1は未訪問
    depth[0] = 0;
    while (!que.empty()) {
        int node = que.front(); que.pop();
        for (auto &xnode : graph[node]) {
            if (depth[xnode] >= 0) {
                continue;
            }
            depth[xnode] = depth[node] + 1;
            que.push(xnode);
        }
    }
    
    REP(i, n) cout << depth[i] << "\n";

    return 0;
}
