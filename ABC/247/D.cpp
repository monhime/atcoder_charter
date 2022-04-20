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
  int q;
  cin >> q;
  deque<pair<ll, ll>> vec_Q;
  vector<ll> Q_c;
  REP(i, q) {
    string s, buf;
    vector<string> vec_s;
    int qq;
    cin >> qq;
    if (qq == 1) {
      ll x, c;
      cin >> x >> c;
      vec_Q.emplace_back(make_pair(x, c));
    } else {
      int c;
      cin >> c;
      Q_c.emplace_back(c);
    }
  }
  ll x, c;
  tie(x, c) = vec_Q.front();
  vec_Q.pop_front();
  for (auto q : Q_c) {
    ll ans = 0ll;
    while (q) {
      if (c >= q) {
        ans += x * q;
        c -= q;
        q = 0;
      } else {
        ans += x * c;
        q -= c;
        tie(x, c) = vec_Q.front();
        vec_Q.pop_front();
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
