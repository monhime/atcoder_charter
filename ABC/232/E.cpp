#include <iostream>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;
constexpr ll MOD = 998244353ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int h, w, k;
  std::cin >> h >> w >> k;
  int x1, y1, x2, y2;
  std::cin >> x1 >> y1 >> x2 >> y2;
  ll ans = 1ll;
  if (k == 1) {
    if ((x1 == x2) ^ (y1 == y2)) {
      std::cout << 1 << "\n";
    } else {
      std::cout << 0 << "\n";
    }
  } else if (k == 2) {
    if ((x1 == x2) && (y1 == y2)) {
      std::cout << (h + w - 2) % MOD << "\n";
    } else if (x1 == x2) {
      std::cout << (w - 2) % MOD << "\n";
    } else if (y1 == y2) {
      std::cout << (h - 2) % MOD << "\n";
    } else {
      std::cout << 2 << "\n";
    }
  }

  return 0;
}
