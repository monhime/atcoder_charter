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
  vector<ll> A(n), cA(n);
  REP(i, n) { cin >> A[i]; }
  cA[0] = A[0];
  FOR(i, 1, n) { cA[i] = cA[i - 1] + A[i]; }
  ll x;
  cin >> x;
  ll sum_A = accumulate(ALL(A), 0ll);
  ll ans = n * (x / sum_A);
  x %= sum_A;
  ans += distance(cA.begin(), lower_bound(ALL(cA), x + 1)) + 1;
  cout << ans << "\n";

  return 0;
}
