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
  vector<int> A(n);
  int a;
  int cur_a = 0;
  REP(i, n) {
    cin >> a;
    cur_a = (cur_a + a) % 360;
    A[i] = cur_a % 360;
  }
  sort(ALL(A));
  int ans = max(A.front(), 360 - A.back());
  REP(i, n - 1) { ans = max(ans, A[i + 1] - A[i]); }
  cout << ans << "\n";
  return 0;
}
