#include <iostream>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int h, w, r, c;
  std::cin >> h >> w >> r >> c;
  int ans = 4;
  if (r == 1) ans--;
  if (r == h) ans--;
  if (c == 1) ans--;
  if (c == w) ans--;
  std::cout << ans << "\n";

  return 0;
}
