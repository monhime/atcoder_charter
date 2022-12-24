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

  int n;
  int a, b;
  cin >> n;
  map<int, vi> graph;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  queue<int> Q;
  Q.emplace(1);
  set<int> visited;
  visited.emplace(1);
  int ans = 1;
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    for (auto& xnode : graph[node]) {
      if (visited.count(xnode)) {
        continue;
      }
      ans = max(ans, xnode);
      visited.emplace(xnode);
      Q.emplace(xnode);
    }
    // cout << node << "\n";
  }
  cout << ans << "\n";

  return 0;
}