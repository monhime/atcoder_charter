#include <algorithm>
#include <iostream>
#include <vector>
constexpr int inf = 1LL << 30;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<std::pair<int, int>> AB(n);
  for (int i = 0; i < n; i++) {
    std::cin >> AB[i].first >> AB[i].second;
  }
  std::vector<std::vector<int>> dp(x + 1, std::vector<int>(y + 1, inf)),
      dp_tmp(x + 1, std::vector<int>(y + 1, inf));

  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    int tako = AB[i].first, tai = AB[i].second;
    for (int j = 0; j <= x; j++) {
      for (int k = 0; k <= y; k++) {
        dp_tmp[j][k] = std::min(dp_tmp[j][k], dp[j][k]);
        int n_j = std::min(x, j + tako);
        int n_k = std::min(y, k + tai);
        dp_tmp[n_j][n_k] = std::min(dp_tmp[n_j][n_k], dp[j][k] + 1);
      }
    }
    dp = dp_tmp;
    for (int j = 0; j < x; j++) {
      std::fill(dp_tmp[j].begin(), dp_tmp[j].end(), inf);
    }
  }
  if (dp[x][y] == inf) {
    std::cout << "-1\n";
  } else {
    std::cout << dp[x][y] << "\n";
  }
  return 0;
}
