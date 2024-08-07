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

int dfs(int node, vb& visited, vvi& graph) {
  if (graph[node].size() == 0) {
    return node;
  }

  for (auto& xnode : graph[node]) {
    if (visited[xnode]) {
      continue;
    }
    visited[xnode] = true;
    dfs(xnode, ans, visited, graph);
    visited[xnode] = false;
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, m;
  cin >> n >> m;

  int a, b;
  vvi graph(n);  // iより強い人
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    graph[b].emplace_back(a);
  }

  vi Ans(n);
  vector<bool> visited(n, false);
  for (int i = 0; i < n; i++) {
    Ans[i] = dfs(i, visited, graph);  // i から見て一番強い人
  }

  return 0;
}