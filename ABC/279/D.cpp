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

double f(double a, double b, ll n) { return n * b + a / sqrt(1 + n); }

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  double a, b;
  cin >> a >> b;

  double min_n = pow(a / (2 * b), 2.0 / 3) - 1.0;
  //   cout << min_n << "\n";
  //   min_n = max(min_n, 0.[
  double ans;
  if (min_n < 1) {
    ans = min(f(a, b, (ll)min_n), f(a, b, (ll)min_n + 1));
  } else {
    ans = min(min(f(a, b, (ll)min_n - 1), f(a, b, (ll)min_n)),
              f(a, b, (ll)min_n + 1));
  }
  cout << setprecision(7);
  cout << ans << "\n";

  return 0;
}