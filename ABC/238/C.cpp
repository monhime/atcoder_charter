#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;
constexpr ll MOD = 998244353ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  int keta_n = to_string(n).length();
  if (keta_n == 1) {
    cout << n << "\n";
    return 0;
  }
  // f(x) = x - (10**(log10(f(x))/10) - 1)
  // f(x) = x + 1 - 10**(log10(f(x))/10)
  ll ko_1 = (n % MOD) * ((n + 1ll) % MOD) % MOD * 499122177ll % MOD;
  ll ko_2 = n % MOD;
  ll ko_3 = 0ll;

  for (int i = 0; i < keta_n - 1; i++) {
    ko_3 = (ko_3 + ((ll)pow(10, i) % MOD) * ((ll)pow(10, i) % MOD) * 9ll) % MOD;
  }
  ko_3 = (ko_3 + ((ll)pow(10, keta_n - 1) % MOD) *
                     (n % MOD - ((ll)pow(10, keta_n - 1ll) % MOD) + 1ll)) %
         MOD;
  cout << (ko_1 + ko_2 - ko_3) % MOD << "\n";

  return 0;
}
