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

class UnionFind {
public:
    vi parents;
    vi size_c;
    int uf_n;
    UnionFind(int n): parents(n), size_c(n, 1) {
        uf_n = n;
        for (int i = 0; i < uf_n; ++i) parents[i] = i; 
    }
    int root(int x) { // 根の検索
        while (parents[x] != x) {
            x = parents[x] = parents[parents[x]];
        }
        return x;
    }
    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (size_c[x] < size_c[y]) swap(x, y);
        size_c[x] += size_c[y];
        parents[y] = x;
        return true;
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return size_c[root(x)];
    }
    vi members(int x){//xと同じグループに属する要素
        int root_x = root(x);
        vi vec_m;
        REP(i, uf_n){
            if (root(i) == root_x){
                vec_m.emplace_back(i);
            }
        }
        return vec_m;
    }
    vi roots(){
        vi vec_roots;
        REP(i, uf_n){
            if (root(i) == i){
                vec_roots.emplace_back(i);
            }
        }
        return vec_roots;
    }
    int group_count(){
        vi vec_roots = roots();
        return vec_roots.size();
    }
    map<int, vi> all_group_members(){
        map<int, vi> uf_map;
        for (auto &r: roots()){
            uf_map[r] = members(r);
        }
        return uf_map;
    }
};


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Pii> P(n);
    vi id(n);

    REP(i, n){
        int x, y;
        cin >> x >> y;
        P[i].first = x - 1;
        P[i].second = y - 1;
        id[i] = P[i].second;
    }
    sort(ALL(P));//x座標について昇順
    set<int> visited;
    UnionFind uf(n);

    int INF = (int)2*pow(10, 6);
    REP(i, n){
        int _min = INF; //連結成分のうち最小要素
        visited.insert(P[i].second);
        while (!visited.empty() && *begin(visited) < P[i].second){//左下にある点すべてに辺を張る
            uf.unite(*begin(visited), P[i].second);
            chmin(_min, *begin(visited)); //連結成分のうち最小要素なら更新
            visited.erase(*begin(visited));
        }
        if (_min != INF) visited.insert(_min); //最小要素だけメモっておく
    }
    REP(i, n){
        cout << uf.size(id[i]) <<"\n";
    }

    return 0;
}
