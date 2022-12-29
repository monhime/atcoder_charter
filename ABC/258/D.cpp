#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;

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

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  ll n, x;
  cin >> n >> x;
  vector<Pll> AB(n);
  ll a, b;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    AB[i] = {a, b};
  }
  vll Sum(n, 0ll);
  Sum[0] = AB[0].first + AB[0].second;
  for (int i = 1; i < n; i++) {
    Sum[i] = Sum[i - 1] + AB[i].first + AB[i].second;
  }
  ll ans = LLONG_MAX;
  // 2回以上やるなら同じステージで
  // 2回以上やるステージがあるとき、それは一番最後
  for (ll last = min(x, n) - 1; last >= 0ll; last--) {
    // last で最終とし、繰り返す
    ll nokori = x - last;
    ans = min(ans, Sum[last] + (nokori - 1ll) * AB[last].second);
  }
  cout << ans << "\n";

  return 0;
}