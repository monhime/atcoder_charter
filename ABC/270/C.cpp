#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
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
using vvi = vector<vector<int>>;
using vll = vector<ll>;

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

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, x, y;
  cin >> n >> x >> y;
  x--;
  y--;

  int a, b;
  vvi graph(n);  // 空の配列n個分
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  queue<int> que;
  que.emplace(x);      // xを頂点とする
  map<int, int> path;  // 子→親
  vector<bool> visited(n, false);
  visited[x] = true;
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto& xnode : graph[node]) {
      if (visited[xnode]) {
        continue;
      }

      path[xnode] = node;
      visited[xnode] = true;
      if (xnode == y) {
        goto A;
      }
      que.emplace(xnode);
    }
  }
A:

  int idx = y;
  vi Ans;
  while (idx != x) {
    Ans.emplace_back(idx);
    idx = path[idx];
  }
  cout << x + 1 << " ";
  reverse(ALL(Ans));
  for (int i = 0; i < Ans.size(); i++) {
    cout << Ans[i] + 1 << " ";
  }
  cout << "\n";

  return 0;
}