#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'

void dfs(int node, std::vector<std::vector<int>> &List,
         std::vector<bool> &visited, const std::vector<std::vector<int>> &graph,
         const std::vector<int> &X) {
  if (node != 0 && graph[node].size() == 1) {
    // 葉のとき
    List[node].emplace_back(X[node]);
    return;
  }
  List[node].emplace_back(X[node]);
  for (auto &xnode : graph[node]) {
    if (visited[xnode]) {
      continue;
    }
    visited[xnode] = true;
    dfs(xnode, List, visited, graph, X);
    for (int i = 0; i < std::min(20, (int)List[xnode].size()); i++) {
      List[node].emplace_back(List[xnode][i]);
    }
  }
  std::sort(List[node].begin(), List[node].end(), std::greater<int>());

  return;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, q;
  std::cin >> n >> q;
  std::vector<int> X(n), Ans(q);
  for (int i = 0; i < n; i++) {
    std::cin >> X[i];
  }

  std::vector<std::vector<int>> graph(n);  //空の配列n個分
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  std::vector<std::vector<int>> List(n);
  std::vector<bool> visited(n, false);
  visited[0] = true;
  dfs(0, List, visited, graph, X);

  int v, k;
  for (int qq = 0; qq < q; qq++) {
    std::cin >> v >> k;
    Ans[qq] = List[v - 1][k - 1];
  }
  for (int i = 0; i < q; i++) {
    std::cout << Ans[i] << "\n";
  }

  return 0;
}
