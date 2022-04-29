#include <iostream>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int x, y, z;
  std::cin >> x >> y >> z;
  // y/x > a/z
  int a = 0;
  while (y * z > a * x) {
    a++;
  }
  std::cout << a - 1 << "\n";

  return 0;
}
