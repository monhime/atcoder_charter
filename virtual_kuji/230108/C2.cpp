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
int dp[61][200000];
int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  ll k;
  cin >> n >> k;
  vi A(n);
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    A[i] = a - 1;
  }
  for (int i = 0; i < n; i++) {
    dp[0][i] = A[i];
  }
  for (int i = 1; i <= 60; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] = dp[i - 1][dp[i - 1][j]];
    }
  }
  int cur = 0;
  for (int i = 60; i >= 0; i--) {
    if (k & (1ll << i)) {
      cur = dp[i][cur];
    }
  }
  cout << cur + 1 << "\n";

  return 0;
}