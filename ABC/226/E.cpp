#include <iostream>
#include <queue>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'
constexpr int MOD = 998244353;
using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);  //空の配列n個分
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  // 1個の連結成分のうち1以上ループが必要
  // 2つ以上ループがあると、出ていく要素が2つ以上の頂点が存在する
  // →ループは1個の連結成分で1つ。連結成分の個数xに対し2^x
  std::queue<int> Q;
  std::vector<bool> visited(n, false);
  int ans = 1;
  std::vector<int> Node_part;
  int cunt_edge;
  for (int i = 0; i < n; i++) {
    if (visited[i]) {
      continue;
    }
    visited[i] = true;
    Node_part.clear();
    Node_part.emplace_back(i);
    ans *= 2;
    ans %= MOD;
    Q.emplace(i);
    while (!Q.empty()) {
      int node = Q.front();
      Q.pop();
      for (auto &xnode : graph[node]) {
        if (visited[xnode]) {
          continue;
        }
        visited[xnode] = true;
        Q.emplace(xnode);
        Node_part.emplace_back(xnode);
      }
    }
    cunt_edge = 0;
    for (const auto &node : Node_part) {
      cunt_edge += graph[node].size();
    }
    cunt_edge /= 2;

    if (cunt_edge != Node_part.size()) {
      std::cout << 0 << "\n";
      return 0;
    }
  }
  std::cout << ans << "\n";

  return 0;
}
