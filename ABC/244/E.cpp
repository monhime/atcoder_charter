#include <algorithm>
#include <iostream>
#include <vector>
constexpr int MOD = 998244353;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m, k, s, t, x;
  std::cin >> n >> m >> k >> s >> t >> x;
  s--;
  t--;
  x--;
  std::vector<std::vector<int>> graph(m);  //空の配列n個分
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  // 長さkで、A = {s, ..., t}かつA[i]--A[i+1]が存在する数列の個数（1<=Ai<=n)
  // S->Tで k - 2 個の街を途中経由して行く経路の個数
  // （ただし、頂点xを偶数回通る）
  // dp[i][j][k] = (i街目で、jの街にいる場合の数（k:xの街に偶数回?）)
  // dp[i + 1][j][0] += Σ(k ∈ adj(j))(j == x ? dp[i][k][1] : dp[i][k][0])
  // dp[i + 1][j][1] += Σ(k ∈ adj(j))(j == x ? dp[i][k][0] : dp[i][k][1])
  // dp[0][s][0] = 1、他0
  // dp[n][t][0]

  std::vector<std::pair<int, int>> dp(n, std::pair<int, int>(0, 0)),
      dp_tmp(n, std::pair<int, int>(0, 0));
  dp[s].first = 1;
  for (int i = 1; i <= k; i++) {
    for (int xnode = 0; xnode < n; xnode++) {
      for (auto &node : graph[xnode]) {
        dp_tmp[xnode].first += (xnode == x ? dp[node].second : dp[node].first);
        dp_tmp[xnode].second += (xnode == x ? dp[node].first : dp[node].second);
        dp_tmp[xnode].first %= MOD;
        dp_tmp[xnode].second %= MOD;
      }
    }
    dp = dp_tmp;
    std::fill(dp_tmp.begin(), dp_tmp.end(), std::pair<int, int>(0, 0));
  }
  std::cout << dp[t].first << "\n";

  return 0;
}
