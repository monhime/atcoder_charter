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
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  vi P(n);
  for (int i = 0; i < n; i++) {
    cin >> P[i];
  }
  vi Delta_P(n);
  for (int i = 0; i < n; i++) {
    if (i - P[i] >= 0) {
      Delta_P[i] = i - P[i];
    } else {
      Delta_P[i] = n + i - P[i];
    }
    // cout << Delta_P[i] << " ";
  }
  int ans = 0;
  vi Delta_P_cunt(n, 0);
  for (int i = 0; i < n; i++) {
    Delta_P_cunt[Delta_P[i]]++;
  }
  for (int i = 0; i < n; i++) {
    int tmp;
    if (i == 0) {
      tmp = Delta_P_cunt[n - 1] + Delta_P_cunt[i] + Delta_P_cunt[i + 1];
    } else if (i == n - 1) {
      tmp = Delta_P_cunt[i - 1] + Delta_P_cunt[i] + Delta_P_cunt[0];
    } else {
      tmp = Delta_P_cunt[i - 1] + Delta_P_cunt[i] + Delta_P_cunt[i + 1];
    }
    ans = max(ans, tmp);
  }
  cout << ans << "\n";

  return 0;
}