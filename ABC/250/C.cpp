#include <iostream>
#include <vector>

int main() {
  int n, q;
  std::cin >> n >> q;

  std::vector<int> Val(n), Pos(n);
  for (int i = 0; i < n; i++) {
    Val[i] = i;
    Pos[i] = i;
  }
  std::vector<int> x(q);
  int xx;
  for (int i = 0; i < q; i++) {
    std::cin >> xx;
    x[i] = xx - 1;
  }

  for (int i = 0; i < q; i++) {
    int p0 = Pos[x[i]];
    int p1 = (p0 == n - 1 ? p0 - 1 : p0 + 1);
    int v0 = Val[p0];
    int v1 = Val[p1];
    std::swap(Val[p0], Val[p1]);
    std::swap(Pos[v0], Pos[v1]);
  }

  for (int i = 0; i < n; i++) {
    std::cout << Val[i] + 1 << " ";
  }
  std::cout << "\n";

  return 0;
}
