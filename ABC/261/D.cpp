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

ll dp[5001][5001];

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, m;
  cin >> n >> m;
  vi X(n);  // i回目で表ならX[i]円もらえる
  for (int i = 0; i < n; i++) {
    cin >> X[i];
  }
  map<int, int> CYmap;  // カウントがxのときCYmap[x]もらえる
  int c, y;
  for (int i = 0; i < m; i++) {
    cin >> c >> y;
    CYmap[c] = y;
  }

  for (int i = 0; i < n; i++) {
    for (int cunt = 0; cunt <= i; cunt++) {
      // i + 1で表のとき
      chmax(dp[i + 1][cunt + 1], dp[i][cunt] + (ll)X[i] + (ll)CYmap[cunt + 1]);
      // i + 1で裏のとき
      chmax(dp[i + 1][0], dp[i][cunt]);
    }
  }
  ll max_maney = 0ll;
  for (int i = 0; i <= n; i++) {
    chmax(max_maney, dp[n][i]);
  }
  cout << max_maney << "\n";
  //   for (int i = 0; i <= n; i++) {
  //     for (int j = 0; j <= n; j++) {
  //       cout << dp[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }

  return 0;
}