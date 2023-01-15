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

void dfs(vvi& G, vb& finished, vb& seen, bool& ans, int node, int pre_node) {
  seen[node] = true;  // 行きがけで訪問した
  for (auto& xnode : G[node]) {
    if (xnode == pre_node) {
      ans = true;
      return;
    };  // 逆流を禁止する（DAG上の逆流を許容するならcontinue

    // 完全終了した頂点はスルー
    if (finished[xnode]) continue;

    // サイクル検出
    if (seen[xnode] && !finished[xnode]) {
      ans = true;
      return;
    }

    dfs(G, finished, seen, ans, xnode, node);

    // サイクル検出したならば真っ直ぐに抜けていく
    if (ans) return;
  }
  finished[node] = true;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  vvi graph(2 * n + 1);  // 空の配列n個分

  map<string, int> map_name;  // 名前と頂点番号の対応
  int node = 1;
  string s, t;
  for (int i = 0; i < n; i++) {
    cin >> s >> t;
    int s_num, t_num;
    if (!map_name.count(s)) {
      map_name[s] = node;
      s_num = node;
      node++;
    } else {
      s_num = map_name[s];
    }
    if (!map_name.count(t)) {
      map_name[t] = node;
      t_num = node;
      node++;
    } else {
      t_num = map_name[t];
    }
    // debug(node);
    // debug(s_num);
    // debug(t_num);
    graph[s_num].emplace_back(t_num);
  }
  // for (int i = 0; i <= 2 * n; i++) {
  //   for (auto& a : graph[i]) {
  //     cout << a << " ";
  //   }
  //   cout << "\n";
  // }

  vb finished(2 * n + 1, false);
  vb seen(2 * n + 1, false);
  bool ans = false;
  for (int i = 1; i <= 2 * n; i++) {
    if (seen[i]) {
      continue;
    }
    // debug(i);
    dfs(graph, finished, seen, ans, i, 0);

    if (ans) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}