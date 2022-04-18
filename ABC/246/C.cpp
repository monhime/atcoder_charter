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
  ll k, x;
  cin >> n >> k >> x;
  vector<ll> A(n);
  for (auto &a : A) {
    cin >> a;
  }
  sort(ALL(A), greater<ll>());
  // まず非負の範囲内でクーポン
  for (auto &a : A) {
    if (a / x <= k) {
      k -= a / x;
      a -= a / x * x;
    } else {
      a -= k * x;
      k = 0;
      break;
    }
  }
  // クーポンが余ってたら残りが多いものから使い切る
  sort(ALL(A), greater<ll>());
  for (auto &a : A) {
    if (k) {
      a = 0ll;
      k--;
    } else {
      break;
    }
  }
  cout << accumulate(ALL(A), 0ll) << "\n";

  return 0;
}
