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

int n, k;
vector<double> A(1000);
vector<pair<double, double>> XY(1000);

bool question(double r) {  // xxxxooo
  for (int j = 0; j < n; j++) {
    double x, y;
    tie(x, y) = XY[j];
    bool akari_flag = false;
    for (int i = 0; i < k; i++) {
      if (pow(x - XY[A[i]].first, 2) + pow(y - XY[A[i]].second, 2) <
          pow(r, 2)) {
        akari_flag = true;
      }
    }
    if (!akari_flag) {
      return false;
    }
  }
  return true;
}

double binary_search() {
  double left = 0.0;
  double right = std::pow(10, 6);
  while (right - left > 1e-6) {
    double m = (left + right) / 2;
    if (question(m))  // xxxxxoooo
      right = m;
    else
      left = m;
  }
  return left;  // xとoの境界部分の左
  //   return right;  //  xとoの境界部分の右
}

int main() {
  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    cin >> A[i];
    A[i]--;
  }

  int x, y;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    XY[i] = {x, y};
  }

  cout << setprecision(7);
  cout << binary_search() << "\n";

  return 0;
}