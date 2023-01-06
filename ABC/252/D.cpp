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
ll dp[200001][4];

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  map<int, int> mapA;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    mapA[a]++;
  }
  int m = mapA.size();
  int i = 0;
  dp[0][0] = 1ll;
  for (auto& mp : mapA) {
    for (int j = 0; j < 4; j++) {
      dp[i + 1][j] += dp[i][j];
      if (j < 3) {
        dp[i + 1][j + 1] += dp[i][j] * (ll)mp.second;
      }
    }
    i++;
  }
  cout << dp[i][3] << "\n";

  return 0;
}