#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 998244353;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> dp(9), dp_tmp(9);
  REP(i, 9) { dp[i] = 1ll; }
  REP(i, n - 1) {
    REP(j, 9) {
      if (j == 0) {
        dp_tmp[j] = (dp[j] + dp[j + 1]) % MOD;
      } else if (j == 8) {
        dp_tmp[j] = (dp[j - 1] + dp[j]) % MOD;
      } else {
        dp_tmp[j] = (dp[j - 1] + dp[j] + dp[j + 1]) % MOD;
      }
    }
    dp = dp_tmp;
  }
  cout << accumulate(ALL(dp), 0ll) % MOD << "\n";

  return 0;
}
