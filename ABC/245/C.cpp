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

  int n, k;
  cin >> n >> k;
  vector<int> A(n), B(n);
  REP(i, n) { cin >> A[i]; }
  REP(i, n) { cin >> B[i]; }
  bool flag_a_pre = true;
  bool flag_b_pre = true;
  bool flag_a, flag_b;
  FOR(i, 1, n) {
    if ((abs(A[i] - A[i - 1]) <= k && flag_a_pre) ||
        ((abs(A[i] - B[i - 1]) <= k && flag_b_pre))) {
      flag_a = true;
    } else {
      flag_a = false;
    }
    if ((abs(B[i] - A[i - 1]) <= k && flag_a_pre) ||
        ((abs(B[i] - B[i - 1]) <= k && flag_b_pre))) {
      flag_b = true;
    } else {
      flag_b = false;
    }
    flag_a_pre = flag_a;
    flag_b_pre = flag_b;
  }
  if (n == 1 || flag_a || flag_b) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
