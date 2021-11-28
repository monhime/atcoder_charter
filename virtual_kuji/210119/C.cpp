#include <bits/stdc++.h>
using namespace std;

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
    vi L(n);
    REP(i, n) cin >> L[i];

    sort(ALL(L));

    ll ans = 0ll;
    REP(i_a, n - 2){
        FOR(i_b, i_a + 1, n - 1){
            ll idx = lower_bound(L.begin(), L.end(), L[i_a] + L[i_b]) - L.begin();
            ans += idx - 1 - i_b;
        }
    }
    cout << ans << "\n";


    return 0;
}
