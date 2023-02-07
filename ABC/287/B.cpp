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

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, m;
  cin >> n >> m;
  vector<string> S(n), T(m);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> T[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    bool is_same = false;
    for (int j = 0; j < m; j++) {
      bool each_is_same = true;
      for (int k = 0; k < 3; k++) {
        if (S[i][3 + k] != T[j][k]) {
          each_is_same = false;
          break;
        }
      }
      if (each_is_same) {
        is_same = true;
        break;
      }
    }
    if (is_same) {
      ans++;
    }
  }
  cout << ans << "\n";

  return 0;
}