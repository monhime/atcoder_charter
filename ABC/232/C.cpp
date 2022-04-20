#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {1, 0}, dx[4] = {0, 1};
using ll = long long;
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<string> C(h);
  REP(i, h) { cin >> C[i]; }
  int cunt = 0;
  vector<vector<int>> D(h, vector<int>(w, inf));
  queue<pair<int, int>> Q;
  Q.emplace(make_pair(0, 0));
  D[0][0] = 1;
  while (!Q.empty()) {
    pair<int, int> p = Q.front();
    Q.pop();
    for (int i = 0; i < 2; i++) {
      int ny = p.first + dy[i], nx = p.second + dx[i];
      if (0 <= nx && nx < w && 0 <= ny && ny < h && C[ny][nx] != '#' &&
          D[ny][nx] == inf) {
        Q.emplace(make_pair(ny, nx));
        D[ny][nx] = D[p.first][p.second] + 1;
        chmax(cunt, D[ny][nx]);
      }
    }
  }
  int ans = 0;
  REP(i, h) {
    REP(j, w) {
      if (D[i][j] < inf) {
        chmax(ans, D[i][j]);
      }
    }
  }
  cout << ans << "\n";

  return 0;
}
