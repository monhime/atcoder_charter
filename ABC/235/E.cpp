#include <iostream>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

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
    for (auto& r : roots()) {
      uf_map[r] = members(r);
    }
    return uf_map;
  }
};

struct edge {
  int a, b, cost, q_flag;
  // コストの大小で順序定義
  bool operator<(const edge& e) { return cost < e.cost; }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<edge> Edges;
  int a, b, c;
  for (int i = 0; i < m; i++) {
    std::cin >> a >> b >> c;
    a--;
    b--;
    Edges.emplace_back(edge{a, b, c, -1});
  }
  for (int i = 0; i < q; i++) {
    std::cin >> a >> b >> c;
    a--;
    b--;
    Edges.emplace_back(edge{a, b, c, i});
  }
  std::sort(Edges.begin(), Edges.end());
  UnionFind UF(n);

  int edge_size = m + q;
  std::vector<bool> Ans(q, false);
  for (int i = 0; i < edge_size; i++) {
    const edge& e = Edges[i];

    if (!UF.same(e.a, e.b)) {
      if (e.q_flag >= 0) {  // クエリの辺なら
        Ans[e.q_flag] = true;
      } else {
        UF.unite(e.a, e.b);
      }
    }
  }
  for (int i = 0; i < q; i++) {
    std::cout << (Ans[i] ? "Yes" : "No") << "\n";
  }

  return 0;
}
