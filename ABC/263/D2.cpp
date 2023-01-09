#include <bits/stdc++.h>
using namespace std;
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

  int n;
  ll l, r;
  cin >> n >> l >> r;

  vll f(n + 1), g(n + 1);
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  f[0] = 0ll;
  for (int i = 0; i < n; i++) {
    f[i + 1] = min(f[i] + A[i], l * (i + 1));
  }
  //   for (int i = 0; i <= n; i++) {
  //     cout << f[i] << " ";
  //   }
  //   cout << "\n";

  g[0] = 0ll;
  for (int i = 0; i < n; i++) {
    g[i + 1] = min(g[i] + A[n - i - 1], r * (i + 1));
  }

  //   for (int i = 0; i <= n; i++) {
  //     cout << g[i] << " ";
  //   }
  //   cout << "\n";

  ll min_sum = LLONG_MAX;
  for (int i = 0; i <= n; i++) {
    chmin(min_sum, f[i] + g[n - i]);
  }
  cout << min_sum << "\n";

  return 0;
}