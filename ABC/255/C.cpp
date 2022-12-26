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

  ll x, a, d, n;
  cin >> x >> a >> d >> n;
  ll max_s, min_s;
  if (d >= 0) {
    min_s = a;
    max_s = a + d * (n - 1);
  } else {
    min_s = a + d * (n - 1);
    max_s = a;
  }

  if (x >= max_s) {
    cout << x - max_s << "\n";
    return 0;
  } else if (x <= min_s) {
    cout << min_s - x << "\n";
    return 0;
  }

  if (d == 0) {
    cout << 0 << "\n";
  } else if (d > 0) {
    cout << min((x - a) % d, d - (x - a) % d) << "\n";
  } else {
    d *= -1ll;
    // cout << -(x - a) % d << " " << d - (x - a) % d << "\n";
    cout << min(-(x - a) % d, d + (x - a) % d) << "\n";
  }

  return 0;
}