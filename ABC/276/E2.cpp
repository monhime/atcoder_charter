#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;

template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

class UnionFind {
  /*
  ライブラリ：
    #include <algorithm>
    #include <iostream>
    #include <map>
    #include <tuple>
    #include <vector>
  */
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
  int size(int x) { return size_c[root(x)]; }  // 同一グループの要素数　O(α(N))
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
  std::vector<int> roots() {  // 親の頂点リストO(Nα(N))
    std::vector<int> vec_roots;
    for (int i = 0; i < uf_n; ++i) {
      if (root(i) == i) {
        vec_roots.emplace_back(i);
      }
    }
    return vec_roots;
  }
  int group_count() {  // グループの個数 O(Nα(N))
    std::vector<int> vec_roots = roots();
    return vec_roots.size();
  }
  // 各グループリスト O(Nα(N))
  std::map<int, std::vector<int>> all_group_members() {
    std::map<int, std::vector<int>> uf_map;
    for (auto& r : roots()) {
      uf_map[r] = members(r);
    }
    return uf_map;
  }
};

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int h, w, s;
  cin >> h >> w;
  vector<string> C(h);
  for (int i = 0; i < h; i++) {
    cin >> C[i];
    for (int j = 0; j < w; j++) {
      if (C[i][j] == 'S') {
        s = i * w + j;
      }
    }
  }
  UnionFind UF(h * w);
  for (int node_y = 0; node_y < h; node_y++) {
    for (int node_x = 0; node_x < w; node_x++) {
      int node = node_y * w + node_x;
      if (node == s || C[node_y][node_x] == '#') {
        continue;
      }
      for (int k = 0; k < 4; k++) {
        int xnode_y = node_y + dy[k];
        int xnode_x = node_x + dx[k];
        if (xnode_y < 0 || xnode_y >= h || xnode_x < 0 || xnode_x >= w) {
          continue;
        }
        int xnode = xnode_y * w + xnode_x;
        if (C[xnode_y][xnode_x] == '.') {
          UF.unite(node, xnode);
        }
      }
    }
  }
  int s_y = s / w;
  int s_x = s % w;
  // 端こえてるときには⁉
  for (int i = 0; i < 3; i++) {
    int node_i_y = s_y + dy[i];
    int node_i_x = s_x + dx[i];
    if (node_i_y < 0 || node_i_y >= h || node_i_x < 0 || node_i_x >= w ||
        C[node_i_y][node_i_x] == '#') {
      continue;
    }
    int node_i = node_i_y * w + node_i_x;
    for (int j = i + 1; j < 4; j++) {
      int node_j_y = s_y + dy[j];
      int node_j_x = s_x + dx[j];
      if (node_j_y < 0 || node_j_y >= h || node_j_x < 0 || node_j_x >= w ||
          C[node_j_y][node_j_x] == '#') {
        continue;
      }
      int node_j = node_j_y * w + node_j_x;
      if (UF.same(node_i, node_j)) {
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";
  return 0;
}