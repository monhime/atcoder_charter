#include <iostream>
#include <string>
#include <unordered_map>
#define MAX_A 200000

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::unordered_map<int, long long> mapA;
  int a;
  for (int i = 0; i < n; i++) {
    std::cin >> a;
    mapA[a]++;
  }
  long long ans = 0LL;
  for (int r = 1; r <= MAX_A; r++) {
    for (int p = 1; r * p <= MAX_A; p++) {
      ans += mapA[r * p] * mapA[r] * mapA[p];
    }
  }
  std::cout << ans << "\n";

  return 0;
}
