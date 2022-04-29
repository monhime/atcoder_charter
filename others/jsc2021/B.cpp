#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<int> X(1000, 0);
  int a, b;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    X[a - 1]++;
  }
  for (int i = 0; i < m; i++) {
    std::cin >> b;
    X[b - 1]++;
  }
  for (int i = 0; i < 1000; i++) {
    if (X[i] == 1) {
      std::cout << i + 1 << " ";
    }
  }
  std::cout << "\n";

  return 0;
}
