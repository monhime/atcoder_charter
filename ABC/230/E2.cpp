#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, k_0, ans = 0ll;
  cin >> n;
  k_0 = (ll)sqrt(n);
  for (ll k = 1ll; k <= k_0; k++) {
    ans += (n / k - n / (k + 1ll)) * k;
  }
  for (ll i = 1ll; i <= n / (k_0 + 1ll); i++) {
    ans += n / i;
  }

  cout << ans << "\n";

  return 0;
}
