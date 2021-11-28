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

constexpr long long MOD = 10000000000000;
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
template<class T>
vector<vector<T>> prod_mat_mod(const vector<vector<T>>& M1, const vector<vector<T>>& M2){
    int n1 = M1.size();
    int n2 = M2.size();
    int n3 = M2.at(0).size();
    vector<vector<T>> M3(n1, vector<T>(n3, 0));
    REP(i, n1) REP(k, n3) REP(j, n2){
        M3[i][k] = (M3[i][k] + M1[i][j] * M2[j][k]) % MOD;
    }
    return M3;
}
//行列(n*n)の累乗(k)の余り
template<class T>
vector<vector<T>> pow_mat_mod(vector<vector<T>>& M1, int k){
    int n = M1.size();
    vector<vector<T>> M2(n, vector<T>(n, 0));
    REP(i, n) M2[i][i] = 1;
    while (k){
        if (k & 1) M2 = prod_mat_mod(M1, M2);
        M1 = prod_mat_mod(M1, M1);
        k >>= 1;
    }
    return M2;
}
int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vvll A(3, vll(3, 2ll));//llなら0ll、関数側引数変更不要
    A[0][0] = 1ll;

    vvll B = pow_mat_mod(A, 15);
    
    REP(i, 3){
        REP(j, 3){
            cout << B[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
