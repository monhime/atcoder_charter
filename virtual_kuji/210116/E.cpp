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

double dp[101][101][101];

double f(int a, int b, int c){
    if (dp[a][b][c]){
        return dp[a][b][c];
    }
    if (a == 100 || b == 100 || c == 100){
        return 0;
    }
    double ans = 0;
    ans += (f(a + 1, b, c) + 1)*a/(double)(a + b + c);
    ans += (f(a, b + 1, c) + 1)*b/(double)(a + b + c);
    ans += (f(a, b, c + 1) + 1)*c/(double)(a + b + c);
    //cout << a << " " << b << " " << c << " " << ans <<"\n";
    dp[a][b][c] = ans;
    return ans;
    
}

int main(){
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    printf("%.10f\n", f(a, b, c));

    return 0;
}
