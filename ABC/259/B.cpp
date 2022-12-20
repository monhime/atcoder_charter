#include <bits/stdc++.h>
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
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
  //   ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  //   cin.tie(nullptr);             // インタラクティブ実行不可

  double a, b, d;
  cin >> a >> b >> d;
  double pi = 3.141592653589793;
  cout << setprecision(7);
  cout << a * cos(d * pi / 180) - b * sin(d * pi / 180) << " ";
  cout << b * cos(d * pi / 180) + a * sin(d * pi / 180) << "\n";

  return 0;
}