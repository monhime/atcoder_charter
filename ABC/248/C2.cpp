#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr long long MOD = 998244353ll;
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

int dp[51][2501];

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, m, k;
  cin >> n >> m >> k;

  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int cur_sum = 0; cur_sum < k; cur_sum++) {
      for (int next_a = 1; next_a <= min(m, k - cur_sum); next_a++) {
        dp[i + 1][cur_sum + next_a] += dp[i][cur_sum];
        dp[i + 1][cur_sum + next_a] %= MOD;
      }
    }
  }
  int ans = 0;
  for (int i = n; i <= k; i++) {
    ans += dp[n][i];
    ans %= MOD;
  }

  cout << ans << "\n";

  return 0;
}