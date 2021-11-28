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

    int n; cin >> n;
    vvi graph(n);//llなら0ll
    vector<Pii> edge(n);
    REP(i, n - 1){
        int a, b;
        cin >> a >> b;
        graph[a - 1].emplace_back(b - 1);
        graph[b - 1].emplace_back(a - 1);
        edge[i] = {a - 1, b - 1};
    }

    queue<int> que;
    que.emplace(0);
    vi depth(n, -1); //-1は未訪問
    depth[0] = 0;
    while (!que.empty()) {
        int node = que.front(); que.pop();
        for (auto &xnode : graph[node]) {
            if (depth[xnode] >= 0) {
                continue;
            }
            depth[xnode] = depth[node] + 1;
            que.emplace(xnode);
        }
    }

    int q; cin >> q;
    vll C(n, 0);
    REP(qq, q){
        int t, e;
        ll x;
        cin >> t >> e >> x;
        int a, b;
        tie(a, b) = edge[e - 1];
        if (depth[a] > depth[b]){
            if (t == 1){
                C[a] += x;
            }
            else{
                C[0] += x;
                C[a] -= x;
            }
        }
        else{
            if (t == 1){
                C[0] += x;
                C[b] -= x;
            }
            else{
                C[b] += x;
            }            
        }
    }

    queue<int> que2;
    que2.emplace(0);
    while (!que2.empty()) {
        int node = que2.front(); que2.pop();
        for (auto &xnode : graph[node]) {
            if (depth[xnode] < depth[node]) {
                continue;
            }
            C[xnode] += C[node];
            que2.emplace(xnode);
        }
    }
    REP(i, n) cout << C[i] << "\n";

    return 0;
}
