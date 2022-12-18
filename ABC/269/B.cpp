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
  string s;
  vector<bool> flag_row(10, false), flag_col(10, false);
  int ans[4] = {-1, -1, -1, -1};
  for (int i = 0; i < 10; i++) {
    cin >> s;
    for (int j = 0; j < 10; j++) {
      if (s[j] == '#') {
        flag_col[j] = true;
        flag_row[i] = true;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    if (flag_row[i] && (ans[0] == -1)) {
      ans[0] = i + 1;
    }

    if ((flag_col[i]) && (ans[2] == -1)) {
      ans[2] = i + 1;
    }
  }
  for (int i = 9; i >= 0; i--) {
    if ((flag_row[i]) && (ans[1] == -1)) {
      ans[1] = i + 1;
    }
    if ((flag_col[i]) && (ans[3] == -1)) {
      ans[3] = i + 1;
    }
  }
  cout << ans[0] << " " << ans[1] << "\n";
  cout << ans[2] << " " << ans[3] << "\n";

  return 0;
}