#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dx[6] = {-1, 0, -1, 1, 0, 1}, dy[6] = {-1, -1, 0, 0, 1, 1};

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

vector<Pii> XY;
vector<bool> visited;
void dfs(int node) {
  for (int i = 0; i < 6; i++) {
    int next_x = XY[node].first + dx[i];
    int next_y = XY[node].second + dy[i];
    auto iter_next = find(ALL(XY), Pii(next_x, next_y));
    if (iter_next == XY.end()) {
      continue;
    }
    int xnode = distance(XY.begin(), iter_next);
    if (visited[xnode]) {
      continue;
    }
    visited[xnode] = true;
    dfs(xnode);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;

  int a, b;
  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    XY.emplace_back(Pii(x, y));
  }
  visited.assign(n, false);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      ans++;
      dfs(i);
    }
  }
  cout << ans << "\n";

  return 0;
}