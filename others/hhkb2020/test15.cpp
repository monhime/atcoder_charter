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

template <class T>
class SegTree {
    int n;  // 葉の数
    vector<T> data; // データを格納するvector
    T def;  // 初期値かつ単位元
    function<T(T, T)> operation; // 区間クエリで使う処理
    function<T(T, T)> update_f; // 点更新で使う処理
    
    T _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 交差しない
        if (a <= l && r <= b)
            return data[k]; // a,l,r,bの順で完全に含まれる
        else {
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子
            return operation(c1, c2);
        }
    }

public:
    SegTree(size_t _n, T _def, function<T(T, T)> _operation,
                function<T(T, T)> _update_f)
        : def(_def), operation(_operation), update_f(_update_f) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<T>(2 * n - 1, def);
    }
    void update(int i, T x) {
        i += n - 1;
        data[i] = update_f(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
    T query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
    T operator[](int i) { //seg[i]] は葉のi番目の値
        return data[i + n - 1];
    }
};


int main(){
    ios::sync_with_stdio(false); //対話的出力のときはコメントアウト
    std::cin.tie(nullptr);

    
    int n, q;
    cin >> n >> q;
    SegTree<ll> seg(n, (1LL<<31) - 1, 
            [](ll a, ll b) { return min(a, b); }, 
            [](ll d, ll x){ return x;}); 
    REP(i, q){
        int com, x, y;
        cin >> com >> x >> y;
        if (com) cout << seg.query(x, y + 1) << "\n";
        else seg.update(x, y);
    }

    return 0;
}
