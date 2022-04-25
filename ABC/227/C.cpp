#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  // a<= b <= c and abc<=n
  // (a, b) -> b <= c <= n/ab (1 <= b <= 10^5*√10)
  ll ans = 0ll;
  for (ll a = 1ll; a * a * a < n + 1ll; a++) {
    for (ll b = a; a * b * b < n + 1ll; b++) {
      ans += n / (a * b) - b + 1ll;
    }
  }
  cout << ans << "\n";

  return 0;
}
