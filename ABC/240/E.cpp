#include <iostream>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'
void dfs(int node, int cunt, std::vector<bool> &visited,
         std::vector<std::pair<int, int>> &Ans,
         const std::vector<std::vector<int>> &graph) {
  if (node != 0 && graph[node].size() == 1) {
    // 葉のとき
    cunt++;
    Ans[node] = std::pair<int, int>(cunt, cunt);
    return;
  }
  int left = cunt + 1;
  for (auto &xnode : graph[node]) {
    if (visited[xnode]) {
      continue;
    }
    visited[xnode] = true;
    dfs(xnode, cunt, visited, Ans, graph);

    cunt = Ans[xnode].second;
  }
  Ans[node] = std::pair<int, int>(left, cunt);

  return;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> graph(n);  //空の配列n個分
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  std::vector<bool> visited(n, false);
  std::vector<std::pair<int, int>> Ans(n);
  visited[0] = true;
  dfs(0, 0, visited, Ans, graph);
  for (int i = 0; i < n; i++) {
    std::cout << Ans[i].first << " " << Ans[i].second << "\n";
  }

  return 0;
}
