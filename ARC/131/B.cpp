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

  int h, w;
  cin >> h >> w;
  vector<string> C(h);
  vvi Ans(h, vi(w, 0));

  for (int i = 0; i < h; i++) {
    cin >> C[i];
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (C[i][j] != '.') {
        Ans[i][j] = C[i][j] - '0';
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (Ans[i][j] != 0) {
        continue;
      }
      // C[i][j] == '.'
      vector<bool> iro(6, false);
      for (int k = 0; k < 4; k++) {
        int y = i + dy[k];
        int x = j + dx[k];
        if (y < 0 || y >= h || x < 0 || x >= w) {
          continue;
        }
        if (Ans[y][x] == 0) {
          continue;
        }
        iro[Ans[y][x]] = true;
      }
      for (int k = 1; k < 6; k++) {
        if (!iro[k]) {
          Ans[i][j] = k;
          break;
        }
      }
    }
  }

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cout << Ans[i][j];
    }
    cout << "\n";
  }

  return 0;
}