#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int m;
  std::cin >> m;
  std::vector<std::vector<int>> graph(10);  //空の配列n個分

  std::vector<int> P(8);
  int a, b;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  std::string s = "999999999";
  int p;
  for (int i = 1; i <= 8; i++) {
    std::cin >> p;
    s[p - 1] = i + '0';
  }
  std::queue<std::string> Q;
  Q.emplace(s);
  std::map<std::string, int> map_S;
  map_S[s] = 0;  //初期状態
  while (!Q.empty()) {
    std::string node = Q.front();
    Q.pop();
    int u = node.find('9') + 1;  // 9が置かれてる位置
    for (auto v : graph[u]) {
      // 空白から隣接する各頂点について
      std::string xnode = node;
      std::swap(xnode[u - 1], xnode[v - 1]);
      if (map_S.count(xnode)) {
        continue;
      }
      map_S[xnode] = map_S[node] + 1;
      Q.emplace(xnode);
    }
  }
  std::cout << (map_S.count("123456789") ? map_S["123456789"] : -1) << "\n";

  return 0;
}
