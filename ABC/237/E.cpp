#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'
constexpr long long infll = 1LL << 62;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  std::vector<long long> H(n);
  for (int i = 0; i < n; i++) {
    std::cin >> H[i];
  }

  std::vector<std::vector<int>> graph(n);  //空の配列n個分
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  std::priority_queue<std::pair<long long, int>> pQ;
  pQ.emplace(std::pair<long long, int>(0LL, 0));
  std::vector<long long> Ans(n, infll);  // 距離
  Ans[0] = 0LL;
  long long max_ans = 0LL;
  while (!pQ.empty()) {
    auto node_p = pQ.top();
    int node = node_p.second;
    long long node_ans = -node_p.first;
    pQ.pop();
    long long ans_tmp;
    for (auto &xnode : graph[node]) {
      long long cost = std::max(H[xnode] - H[node], 0LL);
      ans_tmp = node_ans + cost;
      if (Ans[xnode] <= ans_tmp) {
        continue;
      }
      Ans[xnode] = ans_tmp;
      max_ans = std::max(max_ans, H[0] - ans_tmp - H[xnode]);
      pQ.emplace(std::pair<long long, int>(-ans_tmp, xnode));
    }
  }
  std::cout << max_ans << "\n";

  return 0;
}
