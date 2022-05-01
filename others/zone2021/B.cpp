#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
constexpr double inf = std::pow(10, 30);
#define debug(x) std::cerr << #x << ": " << x << '\n'

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;

  double d_u, h_u, d, h, min_k = inf, k;
  std::cin >> n >> d_u >> h_u;

  for (int i = 0; i < n; i++) {
    std::cin >> d >> h;
    k = (h_u - h) / (d_u - d);
    min_k = std::min(k, min_k);
  }
  // y - h_u = k(x-d_u)
  std::cout << std::setprecision(6) << std::max(0.0, -min_k * d_u + h_u)
            << "\n";

  return 0;
}
