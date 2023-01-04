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

  int n, m;
  cin >> n >> m;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  vector<vll> dp(n + 1, vll(m + 1, -llinf));
  dp[0][0] = 0ll;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      chmax(dp[i + 1][j], dp[i][j]);
      if (j < m && dp[i][j] != -llinf) {
        chmax(dp[i + 1][j + 1], dp[i][j] + (ll)(j + 1) * A[i]);
      }
    }
  }
  //   for (int i = 0; i <= n; i++) {
  //     for (int j = 0; j <= m; j++) {
  //       cout << dp[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }

  cout << dp[n][m] << "\n";

  return 0;
}