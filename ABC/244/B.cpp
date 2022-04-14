#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {0, -1, 0, 1}, dx[4] = {1, 0, -1, 0};
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  string t;
  int x = 0;
  int y = 0;
  cin >> t;
  int dir = 0;  //東、南、西、北
  REP(i, n) {
    if (t[i] == 'S') {
      x += dx[dir];
      y += dy[dir];
    } else {
      dir = (dir + 1) % 4;
    }
  }
  cout << x << " " << y << "\n";

  return 0;
}
