#include <iostream>
#include <string>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;
constexpr ll MOD = 998244353ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int t;
  std::cin >> t;
  int n;
  ll ans;
  std::string s;
  // 各テストケースで1文字ずつつO(logx)で計算
  for (int tt = 0; tt < t; tt++) {
    // 入力Sに対し、同じ長さで辞書順に小さく回文の文字列の個数？
    ans = 0ll;
    std::cin >> n >> s;
    ll power_char = 1ll;
    for (int left = (n - 1) / 2; left >= 0; left--) {
      ans += ((ll)(s[left] - 'A')) * power_char;
      ans %= MOD;
      power_char *= (ll)('Z' - 'A') + 1ll;
      power_char %= MOD;
    }

    int left = (n - 1) / 2, right = n / 2;
    bool flag = true;
    while (left >= 0) {
      if (s[left] < s[right]) {
        break;
      } else if (s[left] > s[right]) {
        flag = false;
        break;
      }
      left--;
      right++;
    }
    std::cout << (flag ? (ans + 1ll) % MOD : ans % MOD) << "\n";
  }

  return 0;
}
