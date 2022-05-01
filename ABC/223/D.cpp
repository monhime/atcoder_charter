#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> graph(n);  //空の配列n個分
  std::vector<int> ind(n, 0);              //入次数
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    ind[b]++;
  }
  std::priority_queue<int> Q;  // 辞書順最小を出力する制約がないならqueueでも
  for (int i = 0; i < n; i++) {
    if (!ind[i]) {
      Q.emplace(-i);
    }
  }
  std::vector<int> Ans;
  std::vector<bool> Used(n, false);
  while (!Q.empty()) {
    int node = -Q.top();
    Q.pop();
    if (Used[node]) {  // ２度出て来る場合は不可能、Ansの最終サイズにも注意
      std::cout << "-1\n";
      return 0;
    }
    Ans.emplace_back(node);
    Used[node] = true;
    for (auto &xnode : graph[node]) {
      ind[xnode]--;
      if (!ind[xnode]) {
        Q.emplace(-xnode);
      }
    }
  }
  if (Ans.size() == n) {
    for (auto &a : Ans) {
      std::cout << a + 1 << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << -1 << "\n";
  }

  return 0;
}
