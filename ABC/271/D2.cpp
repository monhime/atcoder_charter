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

bool dp[101][10001];
int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, s;
  cin >> n >> s;
  vector<Pii> AB(n);
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    AB[i] = {a, b};
  }
  dp[0][0] = true;
  for (int i = 0; i < n; i++) {
    int a = AB[i].first;
    int b = AB[i].second;
    for (int j = 0; j <= s; j++) {
      if (j + a <= s) {
        dp[i + 1][j + a] |= dp[i][j];
      }
      if (j + b <= s) {
        dp[i + 1][j + b] |= dp[i][j];
      }
    }
  }
  //   for (int i = 0; i <= n; i++) {
  //     for (int j = 0; j <= s; j++) {
  //       cout << dp[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }

  if (!dp[n][s]) {
    cout << "No\n";
    return 0;
  }
  int cur_sum = s;
  string ans = "";
  for (int i = n; i > 0; i--) {
    if (cur_sum >= AB[i - 1].first && dp[i - 1][cur_sum - AB[i - 1].first]) {
      ans += "H";
      cur_sum -= AB[i - 1].first;
    } else if (cur_sum >= AB[i - 1].second &&
               dp[i - 1][cur_sum - AB[i - 1].second]) {
      ans += "T";
      cur_sum -= AB[i - 1].second;
    } else {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  reverse(ALL(ans));
  cout << ans << "\n";

  return 0;
}