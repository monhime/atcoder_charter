#include <iostream>
#include <set>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, x, y, a;
  std::cin >> n >> x >> y;
  std::vector<std::vector<int>> A;
  std::vector<int> A_part;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    if (a < y || a > x) {
      A.emplace_back(A_part);
      A_part.clear();
      continue;
    }
    A_part.emplace_back(a);
  }
  if (!A_part.empty()) {
    A.emplace_back(A_part);
  }
  auto kumi = [](ll n) { return n * (n + 1ll) / 2ll; };
  ll ans = 0ll;
  for (auto &A_p : A) {
    if (A_p.empty()) {
      continue;
    }
    int left = 0, right = 0, c_x = 0, c_y = 0;
    while (left < A_p.size()) {
      while (right < A_p.size() && (c_x == 0 || c_y == 0)) {
        if (A_p[right] == x) {
          c_x++;
        }
        if (A_p[right] == y) {
          c_y++;
        }
        right++;
      }
      if (c_x > 0 && c_y > 0) {
        ans += (ll)(A_p.size() - right + 1);
      }
      if (A_p[left] == x) {
        c_x--;
      }
      if (A_p[left] == y) {
        c_y--;
      }
      left++;
    }
  }
  std::cout << ans << "\n";

  return 0;
}
