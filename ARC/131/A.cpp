#include <iostream>
#include <string>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  ll a, b;
  std::cin >> a >> b;
  std::string s_a = std::to_string(a), s_b = std::to_string(b);
  std::string s_b_h = std::to_string(b / 2) + (b % 2 ? '5' : '0');
  std::cout << (b == 1 ? "5" : s_b_h) << s_a << "\n";

  return 0;
}
