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
  ll w;
  cin >> n >> w;

  vector<pair<ll, ll>> AB(n);
  ll a, b;
  REP(i, n) {
    cin >> a >> b;
    AB[i] = make_pair(a, b);
  }
  sort(ALL(AB), greater<pair<ll, ll>>());
  ll ans = 0ll;
  ll ans_w = 0ll;
  for (auto &p_ab : AB) {
    ll p_a = p_ab.first;
    ll p_b = p_ab.second;
    if (ans_w + p_b < w) {
      ans += p_a * p_b;
      ans_w += p_b;
    } else {
      cout << ans + (w - ans_w) * p_a << "\n";
      return 0;
    }
  }
  cout << ans << "\n";

  return 0;
}
