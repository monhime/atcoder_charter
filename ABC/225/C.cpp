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

  int n, m;
  cin >> n >> m;

  // mod 7で1, 2, 3, ..., 6, 0
  vector<vector<int>> B(n, vector<int>(m)), X(n, vector<int>(m)),
      Y(n, vector<int>(m));
  REP(i, n) {
    REP(j, m) { cin >> B[i][j]; }
  }
  REP(i, n) {
    REP(j, m) {
      X[i][j] = (B[i][j] - 1) % 7 + 1;
      Y[i][j] = (B[i][j] + 6) / 7;
    }
  }
  string ans = "Yes\n";
  REP(i, n) {
    REP(j, m) {
      if (i > 0 && X[i][j] != X[i - 1][j]) ans = "No\n";
      if (i > 0 && Y[i][j] != Y[i - 1][j] + 1) ans = "No\n";
      if (j > 0 && X[i][j] != X[i][j - 1] + 1) ans = "No\n";
      if (j > 0 && Y[i][j] != Y[i][j - 1]) ans = "No\n";
    }
  }
  cout << ans;

  return 0;
}
