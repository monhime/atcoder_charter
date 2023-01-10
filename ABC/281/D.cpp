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
using vvll = vector<vector<ll>>;

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

  int n, k;
  ll d;
  cin >> n >> k >> d;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<vvll> dp(n + 1, vvll(k + 1, vll(d, -1ll)));
  dp[0][0][0] = 0ll;

  for (int i = 0; i < n; i++) {
    for (int kk = 0; kk <= k; kk++) {
      //   debug(i);
      //   debug(kk);
      for (int j = 0; j < (int)d; j++) {
        if (dp[i][kk][j] == -1ll) {
          continue;
        }
        chmax(dp[i + 1][kk][j], dp[i][kk][j]);
        if (kk < k) {
          chmax(dp[i + 1][kk + 1][(j + A[i]) % d], dp[i][kk][j] + A[i]);
        }
      }
    }
  }

  cout << dp[n][k][0] << "\n";

  return 0;
}