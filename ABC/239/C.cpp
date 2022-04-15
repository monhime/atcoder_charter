#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 > x2) {
    swap(x1, x2);
    swap(y1, y2);
  }
  // 1が同じか左側
  bool f1 =
      (x1 == x2) && ((abs(y2 - y1) == 4) || (abs(y2 - y1) == 2) || (y1 == y2));
  bool f2 = (x1 + 1 == x2) && ((abs(y2 - y1) == 3) || (abs(y2 - y1) == 1));
  bool f3 = (x1 + 2 == x2) && ((abs(y2 - y1) == 4) || (y1 == y2));
  bool f4 = (x1 + 3 == x2) && ((abs(y2 - y1) == 3) || (abs(y2 - y1) == 1));
  bool f5 = (x1 + 4 == x2) && ((abs(y2 - y1) == 2) || (y1 == y2));
  if (f1 || f2 || f3 || f4 || f5) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
