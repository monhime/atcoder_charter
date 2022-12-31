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

  vector<string> S(9);
  int ans = 0;
  for (int i = 0; i < 9; i++) {
    cin >> S[i];
  }

  for (int i = 0; i < 9 * 9 - 10; i++) {
    int y_i = i / 9;
    int x_i = i % 9;

    if (S[y_i][x_i] == '.') {
      continue;
    }

    for (int j = i + 1; j < 9 * 9 - 9; j++) {
      int y_j = j / 9;
      int x_j = j % 9;
      if (S[y_j][x_j] == '.') {
        continue;
      }
      int delta_x = x_j - x_i;
      int delta_y = y_j - y_i;

      if (delta_x < 0) {
        delta_x *= -1;
        delta_y *= -1;
      }

      int y_k = y_j + delta_x;
      int y_l = y_i + delta_x;

      int x_k = x_j - delta_y;
      int x_l = x_i - delta_y;

      int k = y_k * 9 + x_k;
      int l = y_l * 9 + x_l;

      if (!(i < j && j < l && l < k)) {
        continue;
      }

      if (y_k < 9 && x_k >= 0 && x_k < 9 && S[y_k][x_k] == '#' &&
          S[y_l][x_l] == '#') {
        // cout << x_i << " " << y_i << " " << x_j << " " << y_j << " " << x_k
        //      << " " << y_k << " " << x_l << " " << y_l << "\n";
        ans++;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}