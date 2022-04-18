#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<double, double>> AB(n);
  vector<double> T_sum(n, 0), A_sum(n, 0);
  REP(i, n) {
    cin >> AB[i].first >> AB[i].second;
    if (i == 0) {
      A_sum[i] = AB[i].first;
      T_sum[i] = AB[i].first / AB[i].second;
    } else {
      A_sum[i] = AB[i].first + A_sum[i - 1];
      T_sum[i] = AB[i].first / AB[i].second + T_sum[i - 1];
    }
  }
  double t_sum = T_sum[n - 1];
  double t_half = t_sum / 2;
  int t_half_idx =
      distance(T_sum.begin(),
               lower_bound(ALL(T_sum), t_half));  // であうであろう導火線のidx
  double t_left, t_right;
  if (t_half_idx == 0) {
    t_left = 0;
    t_right = t_sum - T_sum[0];
  } else if (t_half_idx == n - 1) {
    t_left = T_sum[n - 2];
    t_right = 0;
  } else {
    t_left = T_sum[t_half_idx - 1];
    t_right = t_sum - T_sum[t_half_idx];
  }
  double t_mid =
      (AB[t_half_idx].first + AB[t_half_idx].second * (t_right + t_left)) /
      (2 * AB[t_half_idx].second);
  if (t_half_idx > 0) {
    cout << A_sum[t_half_idx - 1] + AB[t_half_idx].second * (t_mid - t_left)
         << "\n";
  } else {
    cout << AB[t_half_idx].second * t_mid << "\n";
  }
  return 0;
}
