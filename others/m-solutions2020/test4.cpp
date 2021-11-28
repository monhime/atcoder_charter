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

void product_mat_mod(const vvi& M1, const vvi& M2, vvi& M3){
    int n1 = M1.size();
    int n2 = M2.size();
    int n3 = M2.at(0).size();
    REP(i, n1) REP(k, n3) REP(j, n2){
        M3[i][k] = (M3[i][k] + M1[i][j] * M2[j][k]) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vvll A(n1, vl(n2));
    vvll B(n2, vl(n3));

    REP(i, n1) REP(j, n2) {
        cin >> A.at(i).at(j);
    }
    REP(j, n2) REP(k, n3) {
        cin >> B.at(j).at(k);
    }

    vvll C(n1, vl(n3, 0ll));

    product_mat_mod(A, B, C);
    
    REP(i, n1){
        REP(j, n3){
            cout << C.at(i).at(j) << " ";
        }
        cout << "\n";
    }
    return 0;
}