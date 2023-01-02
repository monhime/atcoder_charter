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

  int n, m;
  cin >> n >> m;
  vector<Pii> direc;
  for (int dx = 0; dx * dx <= m; dx++) {
    int dy = 0;
    while (dy * dy < (m - dx * dx)) {
      dy++;
    }
    if (dy * dy == (m - dx * dx)) {
      direc.emplace_back(Pii(dx, dy));
      direc.emplace_back(Pii(-dx, dy));
      direc.emplace_back(Pii(dx, -dy));
      direc.emplace_back(Pii(-dx, -dy));
    }
  }
  //   for (int i = 0; i < direc.size(); i++) {
  //     cout << direc[i].first << " " << direc[i].second << "\n";
  //   }

  queue<int> Q;
  Q.emplace(0);
  vector<int> kyori(n * n, -1);  // nが大きいときはsetで
  kyori[0] = 0;
  while (!Q.empty()) {
    int node = Q.front();
    Q.pop();

    int node_y = node / n;
    int node_x = node % n;

    for (auto& dxdy : direc) {
      int xnode_x = node_x + dxdy.first;
      int xnode_y = node_y + dxdy.second;
      if (xnode_x >= n || xnode_x < 0 || xnode_y >= n || xnode_y < 0) {
        continue;
      }

      int xnode = xnode_x + xnode_y * n;
      if (kyori[xnode] != -1 && kyori[xnode] <= kyori[node] + 1) {
        continue;
      }
      kyori[xnode] = kyori[node] + 1;
      Q.emplace(xnode);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << kyori[i * n + j] << " ";
    }
    cout << "\n";
  }

  return 0;
}