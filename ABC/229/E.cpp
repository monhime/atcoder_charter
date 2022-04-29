#include <algorithm>
#include <iostream>
#include <map>
#include <tuple>
#include <vector>

class UnionFind {
 public:
  std::vector<int> parents;
  std::vector<int> size_c;
  int uf_n;
  UnionFind(int n) : parents(n), size_c(n, 1) {
    uf_n = n;
    for (int i = 0; i < uf_n; ++i) parents[i] = i;
  }
  int root(int x) {  // 根の検索O(α(N))
    while (parents[x] != x) {
      x = parents[x] = parents[parents[x]];
    }
    return x;
  }
  bool unite(int x, int y) {  // O(α(N))
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (size_c[x] < size_c[y]) std::swap(x, y);
    size_c[x] += size_c[y];
    parents[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }  // O(α(N))
  int size(int x) { return size_c[root(x)]; }             // O(α(N))
  std::vector<int> members(int x) {  // xと同じグループに属する要素 O(Nα(N))
    int root_x = root(x);
    std::vector<int> vec_m;
    for (int i = 0; i < uf_n; ++i) {
      if (root(i) == root_x) {
        vec_m.emplace_back(i);
      }
    }
    return vec_m;
  }
  std::vector<int> roots() {  //親の頂点リストO(Nα(N))
    std::vector<int> vec_roots;
    for (int i = 0; i < uf_n; ++i) {
      if (root(i) == i) {
        vec_roots.emplace_back(i);
      }
    }
    return vec_roots;
  }
  int group_count() {  //グループの個数 O(Nα(N))
    std::vector<int> vec_roots = roots();
    return vec_roots.size();
  }
  //各グループリスト O(Nα(N))
  std::map<int, std::vector<int>> all_group_members() {
    std::map<int, std::vector<int>> uf_map;
    for (auto &r : roots()) {
      uf_map[r] = members(r);
    }
    return uf_map;
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m;
  std::cin >> n >> m;
  int a, b;
  std::vector<std::pair<int, int>> AB(m);
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b;
    if (a > b) {
      std::swap(a, b);
    }
    AB[i] = std::pair<int, int>(a - 1, b - 1);
  }
  sort(AB.begin(), AB.end(), std::greater<std ::pair<int, int>>());
  UnionFind UF(n);
  std::vector<int> Ans(n);
  Ans[n - 1] = 0;
  int edge_idx = 0;
  for (int i = n - 1; i >= 1; i--) {
    int ans = Ans[i] + 1;
    while (edge_idx < m && AB[edge_idx].first >= i) {
      if (!(UF.same(AB[edge_idx].first, AB[edge_idx].second))) {
        ans--;
        UF.unite(AB[edge_idx].first, AB[edge_idx].second);
      }
      edge_idx++;
    }
    Ans[i - 1] = ans;
  }
  for (int i = 0; i < n; i++) {
    std::cout << Ans[i] << "\n";
  }

  return 0;
}
