#include <iostream>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s, t;
  t = "";
  std::cin >> s;

  int s_len = s.size();
  for (int i = 0; i < 6; i++) {
    t += s;
  }

  std::cout << t.substr(0, 6) << "\n";

  return 0;
}
