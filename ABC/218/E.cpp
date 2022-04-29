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
  int root(int x) {  // 根の検索
    while (parents[x] != x) {
      x = parents[x] = parents[parents[x]];
    }
    return x;
  }
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (size_c[x] < size_c[y]) std::swap(x, y);
    size_c[x] += size_c[y];
    parents[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return size_c[root(x)]; }
  std::vector<int> members(int x) {  // xと同じグループに属する要素
    int root_x = root(x);
    std::vector<int> vec_m;
    for (int i = 0; i < uf_n; ++i) {
      if (root(i) == root_x) {
        vec_m.emplace_back(i);
      }
    }
    return vec_m;
  }
  std::vector<int> roots() {
    std::vector<int> vec_roots;
    for (int i = 0; i < uf_n; ++i) {
      if (root(i) == i) {
        vec_roots.emplace_back(i);
      }
    }
    return vec_roots;
  }
  int group_count() {
    std::vector<int> vec_roots = roots();
    return vec_roots.size();
  }
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
  std::vector<std::tuple<int64_t, int, int>> CAB;
  int a, b;
  int64_t c;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    CAB.emplace_back(std::make_tuple(c, a - 1, b - 1));
  }
  std::sort(CAB.begin(), CAB.end());
  UnionFind UF(n);
  int64_t ans = 0LL;
  for (int i = 0; i < m; i++) {
    std::tie(c, a, b) = CAB[i];
    if (!UF.same(a, b)) {
      UF.unite(a, b);
    } else if (c > 0LL) {
      ans += c;
    }
  }
  std::cout << ans << "\n";
  return 0;
}
