#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

vector<ll> make_divisors(ll n) {
  vector<ll> res;
  for (ll i = 1ll; i * i <= n; ++i) {
    if (n % i == 0ll) {
      res.emplace_back(i);
      if (n / i != i) res.emplace_back(n / i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  // vector返すために参照返しした方が？
  vector<ll> vec_dev;
  vec_dev = make_divisors(n);
  ll pre_dev = vec_dev[0];
  ll ans = n;
  for (int i = 1; i < vec_dev.size(); i++) {
    ll dev = vec_dev[i];
    ans += n / dev * (dev - pre_dev);

    pre_dev = dev;
  }
  cout << ans << "\n";

  return 0;
}
