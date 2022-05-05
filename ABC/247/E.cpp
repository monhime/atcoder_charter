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
    for (auto &a : A_p) {
      std::cout << a << " ";
    }
    std::cout << "\n";
    int A_p_size = A_p.size();
    if (A_p_size == 0) {
      continue;
    }
    ll cunt_not_xy = 0ll, ans_not_xy = 0ll;
    std::set<int> set_x, set_y;
    for (int i = 0; i < A_p_size; i++) {
      if (A_p[i] == x) {
        set_x.emplace(i);
        ans_not_xy += kumi(cunt_not_xy);
        cunt_not_xy = 0ll;
      }
      if (A_p[i] == y) {
        set_y.emplace(i);
        ans_not_xy += kumi(cunt_not_xy);
        cunt_not_xy = 0ll;
      }
      if (A_p[i] != x && A_p[i] != y) {
        cunt_not_xy++;
      }
    }
    if (cunt_not_xy) {
      ans_not_xy += kumi(cunt_not_xy);
    }
    debug(ans_not_xy);
    int left, right;
    ll ans_1_xy = 0ll;
    for (auto &s_x : set_x) {
      auto itr_left_y = set_y.upper_bound(s_x);
      if (itr_left_y == set_y.begin()) {
        left = -1;
      } else {
        itr_left_y--;
        left = *itr_left_y;
      }
      auto itr_right_y = set_y.lower_bound(s_x);
      if (itr_right_y == set_y.end()) {
        right = A_p_size;
      } else {
        right = *itr_right_y;
      }
      ans_1_xy += (s_x - left) + (right - s_x) - 1;
      debug(s_x);
      debug(left);
      debug(right);
    }
    debug(ans_1_xy);

    for (auto &s_y : set_y) {
      auto itr_left_x = set_x.upper_bound(s_y);
      if (itr_left_x == set_x.begin()) {
        left = -1;
      } else {
        itr_left_x--;
        left = *itr_left_x;
      }
      auto itr_right_x = set_x.lower_bound(s_y);
      if (itr_right_x == set_x.end()) {
        right = A_p_size;
      } else {
        right = *itr_right_x;
      }
      ans_1_xy += (s_y - left) + (right - s_y) - 1;
      debug(s_y);
      debug(left);
      debug(right);
    }
    debug(ans_1_xy);
    ans += kumi(A_p_size) - (ans_not_xy + ans_1_xy);
  }
  std::cout << ans << "\n";

  return 0;
}
