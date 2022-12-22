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

double S(pair<double, double> A, pair<double, double> B,
         pair<double, double> O) {
  // 点A→点Bが原点から反時計回りでないとき負
  return (A.first - O.first) * (B.second - O.second) -
         (A.second - O.second) * (B.first - O.first);
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  vector<pair<double, double>> XY(4);
  // 点Aを原点へ
  double x, y;
  for (int i = 0; i < 4; i++) {
    cin >> x >> y;
    XY[i] = {x, y};
  }
  for (int i = 0; i < 4; i++) {
    double S1, S2, S3;
    S1 = S(XY[(i + 1) % 4], XY[(i + 2) % 4], XY[i]);
    S2 = S(XY[(i + 2) % 4], XY[(i + 3) % 4], XY[i]);

    if (S1 < 0 || S2 < 0) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
  return 0;
}