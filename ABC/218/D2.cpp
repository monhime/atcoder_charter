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
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  vector<Pii> XY(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    XY[i] = {x, y};
  }
  sort(ALL(XY));

  int ans = 0;

  for (int i = 0; i < n - 1; i++) {
    int x1 = XY[i].first;
    int y1 = XY[i].second;
    for (int j = i + 1; j < n; j++) {
      int x2 = XY[j].first;  // x1 <= x2
      int y2 = XY[j].second;

      if (y1 <= y2) {
        continue;
      }
      // y1 > y2
      //   cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
      if (binary_search(ALL(XY), Pii(x1, y2)) &&
          binary_search(ALL(XY), Pii(x2, y1))) {
        ans++;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}