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

  ll a, b, k;
  cin >> a >> b >> k;
  // a*k^n >= b
  int ans = 0;
  ll srime = a;
  while (true) {
    if (srime >= b) {
      cout << ans << "\n";
      return 0;
    }
    srime *= k;
    ans += 1;
  }

  return 0;
}
