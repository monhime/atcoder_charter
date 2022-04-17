#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<ll, ll>> XY(n);
  ll x, y;
  REP(i, n) {
    cin >> x >> y;
    XY[i] = make_pair(x, y);
  }
  int ans = 0;
  REP(i, n - 2) {
    ll x_i = XY[i].first;
    ll y_i = XY[i].second;
    FOR(j, i + 1, n - 1) {
      ll x_j = XY[j].first;
      ll y_j = XY[j].second;
      FOR(k, j + 1, n) {
        ll x_k = XY[k].first;
        ll y_k = XY[k].second;
        if (!((x_j - x_i) * (y_k - y_i) == (x_k - x_i) * (y_j - y_i))) {
          ans++;
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
