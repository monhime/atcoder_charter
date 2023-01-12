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

int h, w, s;

void dfs(int node, bool& ans, vi& visited, vector<string>& C) {
  int node_y = node / w;
  int node_x = node % w;
  if (ans) {
    return;
  }

  for (int i = 0; i < 4; i++) {
    int xnode_y = node_y + dy[i];
    int xnode_x = node_x + dx[i];
    int xnode = xnode_y * w + xnode_x;
    if (xnode_y < 0 || xnode_y >= h || xnode_x < 0 || xnode_x >= w) {
      continue;
    }
    if (xnode == s && visited[node] + 1 >= 4) {
      ans = true;
      //   debug(node);
      //   debug(xnode);
      //   for (int k = 0; k < h; k++) {
      //     for (int l = 0; l < w; l++) {
      //       cout << visited[k * w + l] << " ";
      //     }
      //     cout << "\n";
      //   }

      return;
    }
    if (visited[xnode] != -1 || C[xnode_y][xnode_x] == '#') {
      continue;
    }
    visited[xnode] = visited[node] + 1;
    dfs(xnode, ans, visited, C);
    visited[xnode] = -1;
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

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
  vector<int> visited(h * w, -1);
  bool ans = false;
  visited[s] = 0;
  dfs(s, ans, visited, C);

  if (ans) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}