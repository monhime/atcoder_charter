#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;
constexpr ll MOD = 998244353ll;
constexpr ll INV2 = 499122177ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  int keta_n = to_string(n).length();
  ll ans = 0ll;
  // f(1) = 1, f(2) = 2, ..., f(9) = 9
  // f(10) = 1, f(11) = 2, ..., f(99) = 90
  // f(100) = 1, f(101) = 2, ..., f(999) = 900
  for (int i = 0; i < keta_n; i++) {
    ll kosuu;
    if (n > (ll)pow(10, i + 1) - 1ll) {
      kosuu = 9ll * (ll)pow(10, i) % MOD;
    } else if (n < (ll)pow(10, i)) {
      break;
    } else {
      kosuu = (n - (ll)pow(10, i) + 1ll) % MOD;
    }
    ans = (ans + kosuu * (kosuu + 1) % MOD * INV2 % MOD) % MOD;
  }
  cout << ans << "\n";

  return 0;
}
