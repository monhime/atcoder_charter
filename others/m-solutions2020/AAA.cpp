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

bool question(vector<int>& A, int m, int k){ //oooooooxxxxxx
    return A[m] < k;
}
int binary_search(int n, vector<int>& A, int k){ 
    int left = 0;
    int right = n;
    while (right - left > 1){
        int m = (left + right) / 2;
        if (question(A, m, k)) left = m; 
        else right = m;
    }
    return left; //questionがoとなる最大のインデックス
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);  

    int n, k;

    cin >> n;
    vector<int> A(n);
    REP(i, n) cin >> A[i];

    cin >> k;

    cout << binary_search(n, A, k) << "\n"; 
    return 0;
}