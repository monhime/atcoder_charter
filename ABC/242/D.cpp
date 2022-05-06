#include <iostream>
#include <string>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

char g(char tt, ll add_num) {
  // 0文字目のときはすすめるだけ
  return 'A' + (tt - 'A' + add_num) % 3;
}

char f(ll t, ll k, const std::string &s) {
  // t回目の試行のk番目の文字
  if (t == 0ll) {
    // 0回目なのでそのまま
    return s[k];
  }
  if (k == 0ll) {
    // 0文字目なのでs[0]かから進めるだけ
    return g(s[0], t);
  }
  // t - 1回目の試行でk/2番目の文字に等しい
  return g(f(t - 1ll, k / 2ll, s), k % 2ll + 1ll);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  int q;
  std::cin >> s >> q;
  ll t, k;
  for (int i = 0; i < q; i++) {
    std::cin >> t >> k;
    std::cout << f(t, k - 1ll, s) << "\n";
  }

  return 0;
}
