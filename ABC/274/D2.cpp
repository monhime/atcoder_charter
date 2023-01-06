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

bool dp_x[1001][20001];
bool dp_y[1001][20001];

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, x, y;
  cin >> n >> x >> y;
  vi A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int MIN_XY = 10000;
  dp_x[0][MIN_XY] = true;
  dp_y[0][MIN_XY] = true;
  dp_x[1][MIN_XY + A[0]] = true;
  dp_y[1][MIN_XY] = true;

  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= 2 * MIN_XY; j++) {
      if (i % 2) {
        dp_x[i + 1][j] |= dp_x[i][j];
        if (j + A[i] <= 2 * MIN_XY) {
          dp_y[i + 1][j + A[i]] |= dp_y[i][j];
        }
        if (j - A[i] >= 0) {
          dp_y[i + 1][j - A[i]] |= dp_y[i][j];
        }
      } else {
        dp_y[i + 1][j] |= dp_y[i][j];
        if (j + A[i] <= 2 * MIN_XY) {
          dp_x[i + 1][j + A[i]] |= dp_x[i][j];
        }
        if (j - A[i] >= 0) {
          dp_x[i + 1][j - A[i]] |= dp_x[i][j];
        }
      }
    }
  }
  //   for (int i = 0; i <= n; i++) {
  //     for (int j = MIN_XY - 2; j <= MIN_XY + 2; j++) {
  //       cout << dp_x[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }
  //   for (int i = 0; i <= n; i++) {
  //     for (int j = MIN_XY - 2; j <= MIN_XY + 2; j++) {
  //       cout << dp_y[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }

  if (dp_x[n][x + MIN_XY] && dp_y[n][y + MIN_XY]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}