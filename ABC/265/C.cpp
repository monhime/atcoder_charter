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
  int h, w;
  cin >> h >> w;
  vector<string> G(h);
  for (int i = 0; i < h; i++) {
    cin >> G[i];
  }
  int cur_row = 0;
  int cur_col = 0;
  int next_row = -1, next_col = -1;
  set<pair<int, int>> set_G;
  set_G.emplace(Pii(cur_row, cur_col));
  while (true) {
    char direc = G[cur_row][cur_col];
    if (direc == 'U') {
      if (cur_row == 0) {
        cout << cur_row + 1 << " " << cur_col + 1 << "\n";
        return 0;
      } else {
        next_row = cur_row - 1;
        next_col = cur_col;
      }
    }
    if (direc == 'D') {
      if (cur_row == h - 1) {
        cout << cur_row + 1 << " " << cur_col + 1 << "\n";
        return 0;
      } else {
        next_row = cur_row + 1;
        next_col = cur_col;
      }
    }
    if (direc == 'L') {
      if (cur_col == 0) {
        cout << cur_row + 1 << " " << cur_col + 1 << "\n";
        return 0;
      } else {
        next_row = cur_row;
        next_col = cur_col - 1;
      }
    }
    if (direc == 'R') {
      if (cur_col == w - 1) {
        cout << cur_row + 1 << " " << cur_col + 1 << "\n";
        return 0;
      } else {
        next_row = cur_row;
        next_col = cur_col + 1;
      }
    }
    // cout << cur_row + 1 << " " << cur_col + 1 << " " << direc << "\n";
    if (set_G.count(Pii(next_row, next_col))) {
      cout << "-1\n";
      return 0;
    }
    set_G.emplace(Pii(next_row, next_col));

    cur_row = next_row;
    cur_col = next_col;
  }

  return 0;
}