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

struct edge {
  /*
  入力方法
  std::cin >> a >> b >> c;
  a--;
  b--;
  Edges.emplace_back(edge{a, b, c});

  ソート
  std::sort(Edges.begin(), Edges.end());
  */
  int a, cost;
  // コストの大小で順序定義
  bool operator<(const edge& e) { return cost < e.cost; }
};

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<edge>> Edges(n);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    Edges[a].emplace_back(edge{b, c});
    Edges[b].emplace_back(edge{a, c});
  }
  vi S(k);
  for (int i = 0; i < k; i++) {
    cin >> S[i];
  }

  queue<Pii> Q;
  Q.emplace(Pii(0, 1));
  vector<bool> visited(n, false);  // nが大きいときはsetで
  visited[0] = true;
  int ans = 0;
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();
    for (auto& xnode : Edges[node]) {
      if (visited[xnode.a]) {
        continue;
      }
      ans++;
      visited[xnode] = true;
      Q.emplace(xnode);
    }
  }

  return 0;
}