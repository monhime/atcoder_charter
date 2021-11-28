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

//区間[2,n]の値の素因数分解 前処理O(nloglogn)クエリO(logn)
template <typename T>
struct prime_fact_query{
    vector<T> spf;
    prime_fact_query(T n) { // 前処理。spf を求める
        spf.assign(n + 1, 0);
        for (T i = 0; i <= n; i++) spf[i] = i;
        for (T i = 2; i * i <= n; i++) {
            if (spf[i] == i) {
                for (T j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }
    }
    map<T, T> get(T n) { // nの素因数分解を求める
        map<T, T> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};


struct PrimeFact { //前処理O(nloglogn)クエリO(logn)
    vector<int> spf;
    PrimeFact(int n) {// 前処理。spf を求める
        spf.assign(n + 1, 0);
        for (int i = 0; i <= n; i++) spf[i] = i;//#ふるい（素数ならその値）
        for (int i = 2; i * i <= n; i++) {//素数リスト作成
            if (spf[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j)
                        spf[j] = i; //最小の素因数を代入
                }
            }
        }
    }
    bool is_prime(int n){
        if (spf[n] == n) return true;
        else return false;
    }
    map<int, int> get(int n) { // nの素因数分解を求める
        map<int, int> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};


int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n = 15000000;
    PrimeFact p_f(n);

    map<int, int> m = p_f.get(123341);
    for (auto &mm: m)
        cout << mm.first << ": " << mm.second << ", ";
    cout << p_f.is_prime(123341) << "\n";
    return 0;
}
