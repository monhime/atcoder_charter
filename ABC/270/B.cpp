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
  int x, y, z;
  cin >> x >> y >> z;

  // ハンマーを使わなくても行ける
  int ok_flag = -1;
  if (0 < y) {
    if (x < y) {
      ok_flag = abs(x);
    } else if (z < y) {  // 0 < y < x
      if (z < 0) {
        ok_flag = 2 * abs(z) + x;
      } else {
        ok_flag = x;
      }
    }
  } else {  // y < 0
    if (y < x) {
      ok_flag = abs(x);
    } else if (y < z) {  // x < y < 0
      if (z > 0) {
        ok_flag = 2 * z + abs(x);
      } else {
        ok_flag = abs(x);
      }
    }
  }
  cout << ok_flag << "\n";

  return 0;
}