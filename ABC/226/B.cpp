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
  cin >> n;
  vector<vector<int>> A(n);
  vector<int> L(n);
  int a;
  REP(i, n) {
    cin >> L[i];
    REP(j, L[i]) {
      cin >> a;
      A[i].emplace_back(a);
    }
  }
  sort(ALL(A));

  int ans = 1;
  REP(i, n - 1) {
    int j = 0;
    if (A[i].size() != A[i + 1].size()) {
      ans++;
      continue;
    }
    REP(j, A[i].size()) {
      if (A[i][j] != A[i + 1][j]) {
        ans++;
        break;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
