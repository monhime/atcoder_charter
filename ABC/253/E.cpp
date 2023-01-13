#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 998244353;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;

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

  int n, m, k;
  cin >> n >> m >> k;
  vvi dp(n, vi(m + 1, 0)), dp_C(n, vi(m + 1, 0));
  for (int i = 1; i <= m; i++) {
    dp[0][i] = 1;
    dp_C[0][i] = dp_C[0][i - 1] + 1;
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 1; j <= m; j++) {
      if (k == 0) {
        dp[i + 1][j] = (dp[i + 1][j] + dp_C[i][m]) % MOD;
      } else {
        if (j >= k) {
          dp[i + 1][j] = (dp[i + 1][j] + dp_C[i][j - k]) % MOD;
        }
        if (j <= m - k + 1) {
          dp[i + 1][j] = (dp[i + 1][j] + dp_C[i][m]) % MOD;
          dp[i + 1][j] = (dp[i + 1][j] - dp_C[i][j + k - 1] + MOD) % MOD;
        }
      }
      dp_C[i + 1][j] = (dp_C[i + 1][j - 1] + dp[i + 1][j]) % MOD;
    }
  }
  cout << dp_C[n - 1][m] << "\n";

  //   for (int i = 0; i < n; i++) {
  //     for (auto& a : dp[i]) {
  //       cout << a << " ";
  //     }
  //     cout << "\n";
  //   }

  return 0;
}