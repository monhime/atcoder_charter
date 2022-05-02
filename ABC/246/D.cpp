#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'

int64_t f(int64_t a, int64_t b) {
  return a * a * a + a * a * b + a * b * b + b * b * b;
}

bool question(int64_t a, int64_t b, int64_t x) {  // xxxxooo
  return f(a, b) >= x;
}
int binary_search(int64_t a, int64_t x) {
  int64_t left = a;
  int64_t right = (int64_t)std::pow(10, 6);
  while (right - left > 1) {
    int64_t m = (left + right) / 2LL;
    if (question(a, m, x))  // xxxxxoooo
      right = m;
    else
      left = m;
  }
  return left;  // xとoの境界部分の左
  //   return right;  //  xとoの境界部分の右
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int64_t n;
  std::cin >> n;
  int64_t a = 0ll, x;
  std::vector<int64_t> X;
  while (true) {
    // debug(a);
    if ((x = 4 * a * a * a) >= n) {
      X.emplace_back(x);
      break;
    }
    X.emplace_back(f(a, binary_search(a, n)));
    a++;
  }
  std::sort(X.begin(), X.end());
  std::cout << X[0] << "\n";

  return 0;
}
