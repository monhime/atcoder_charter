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

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  ll n, m;
  cin >> n >> m;

  int a, b;
  vvi graph(n);  // 空の配列n個分
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    a--;
    b--;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }

  ll ans = n * (n - 1ll) / 2ll - m;

  vector<int> color(n, -1);  // 未探索-1，黒1，白0
  for (int v = 0; v < n; v++) {
    if (color[v] != -1) {
      // vを含む連結成分はもう見た
      continue;
    }

    queue<int> Q;
    color[v] = 0;
    Q.emplace(v);
    ll white = 1ll;
    ll black = 0ll;

    while (!Q.empty()) {
      int node = Q.front();
      Q.pop();
      for (auto& xnode : graph[node]) {
        if (color[xnode] != -1) {
          if (color[xnode] == color[node]) {
            cout << 0 << "\n";
            return 0;
          }
          continue;
        }
        if (color[node] == 0) {
          color[xnode] = 1;  // 白へ
          black++;
        } else {
          color[xnode] = 0;  // 白へ
          white++;
        }
        Q.emplace(xnode);
      }
    }
    ans -= white * (white - 1ll) / 2ll;
    ans -= black * (black - 1ll) / 2ll;
  }
  cout << ans << "\n";

  return 0;
}