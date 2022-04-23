#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;
constexpr int MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<vector<int>> dp(n, vector<int>(10, 0));
  dp[0][A[0]]++;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][(j + A[i]) % 10] += dp[i - 1][j];
      dp[i][(j + A[i]) % 10] %= MOD;
      dp[i][(j * A[i]) % 10] += dp[i - 1][j];
      dp[i][(j * A[i]) % 10] %= MOD;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << dp[n - 1][i] << "\n";
  }

  return 0;
}
