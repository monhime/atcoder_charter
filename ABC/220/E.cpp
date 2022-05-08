#include <iostream>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

void sub_tree_cunt(const int node, const int parent, const int depth,
                   std::vector<ll> &Sub, std::vector<ll> &Ans,
                   const std::vector<std::vector<int>> &graph) {
  Ans[0] += (ll)depth;  // 頂点0 だけ Σ[1<=i<=n]distance(0, i)を求める
  for (auto &xnode : graph[node]) {
    if (xnode == parent) {
      continue;
    }
    sub_tree_cunt(xnode, node, depth + 1, Sub, Ans, graph);
    Sub[node] += Sub[xnode];
  }
  return;
}

void dfs(const int node, const int parent, const int n, std::vector<ll> &Ans,
         const std::vector<ll> &Sub,
         const std::vector<std::vector<int>> &graph) {
  for (auto xnode : graph[node]) {
    if (xnode == parent) {
      continue;
    }
    Ans[xnode] = Ans[node] - 2ll * Sub[xnode] + (ll)n;
    dfs(xnode, node, n, Ans, Sub, graph);
  }

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
  std::vector<ll> Sub(n, 1ll), Ans(n);
  sub_tree_cunt(0, -1, 0, Sub, Ans, graph);
  dfs(0, -1, n, Ans, Sub, graph);
  for (int i = 0; i < n; i++) {
    std::cout << Ans[i] << "\n";
  }

  return 0;
}
