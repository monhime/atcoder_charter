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
  vector<string> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }

  for (int i = 0; i <= n - 9; i++) {
    for (int j = 0; j <= m - 9; j++) {
      // 左上が(i, j)
      bool tak_flag = true;
      for (int r = 0; r < 9; r++) {
        if (r < 3 &&
            !((S[i + r].substr(j, 3) == "###") && S[i + r][j + 3] == '.')) {
          tak_flag = false;
          break;
        }
        if (r == 3 && !(S[i + r].substr(j, 4) == "....")) {
          tak_flag = false;
          break;
        }
        if (r == 5 && !(S[i + r].substr(j + 5, 4) == "....")) {
          tak_flag = false;
          break;
        }

        if (r >= 6 &&
            !((S[i + r].substr(j + 6, 3) == "###") && S[i + r][j + 5] == '.')) {
          tak_flag = false;
          break;
        }
      }
      if (tak_flag) {
        cout << i + 1 << " " << j + 1 << "\n";
      }
    }
  }

  return 0;
}