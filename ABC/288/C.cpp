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

  int n, m;
  cin >> n >> m;
  UnionFind UF(n);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (UF.same(a, b)) {
      ans++;
    } else {
      UF.unite(a, b);
    }
  }
  cout << ans << "\n";

  return 0;
}