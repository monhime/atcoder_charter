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
ll dp[100001][5];
// 時刻T[i]までについて、今jにいるときに捕まえられる大きさの合計の最大値

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  int t, x, a;
  int pre_t = 0;
  for (int i = 1; i <= n; i++) {
    cin >> t >> x >> a;
    for (int pre_x = 0; pre_x <= min(pre_t, 4); pre_x++) {
      for (int cur_x = 0; cur_x <= 4; cur_x++) {
        if (abs(cur_x - pre_x) > t - pre_t) {
          continue;
        }
        if (cur_x == x) {
          chmax(dp[i][cur_x], dp[i - 1][pre_x] + (ll)a);
        } else {
          chmax(dp[i][cur_x], dp[i - 1][pre_x]);
        }
      }
    }
    pre_t = t;
  }
  //   for (int i = 0; i < n + 1; i++) {
  //     for (int j = 0; j < 5; j++) {
  //       cout << dp[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }

  ll ans = 0ll;
  for (int i = 0; i <= 4; i++) {
    chmax(ans, dp[n][i]);
  }
  cout << ans << '\n';

  return 0;
}