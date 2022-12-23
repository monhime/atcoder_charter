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

template <class T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
template <class T>
T lcm(T a, T b) {
  return a * b / gcd(a, b);
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  // 全体の総和- Aの倍数の総和-Bの倍数の総和+A*Bの倍数の総和
  ll n, a, b, ans;
  cin >> n >> a >> b;
  ans = n * (n + 1ll) / 2ll;
  ll lcm_ab = lcm(a, b);
  ll kosu_x_a = n / a;
  ll kosu_x_b = n / b;
  ll kosu_x_lcm_ab = n / lcm_ab;
  ll S_x_a = a * (kosu_x_a * (kosu_x_a + 1ll) / 2ll);
  ll S_x_b = b * (kosu_x_b * (kosu_x_b + 1ll) / 2ll);
  ll S_x_lcm_ab = lcm_ab * (kosu_x_lcm_ab * (kosu_x_lcm_ab + 1ll) / 2ll);
  cout << ans - S_x_a - S_x_b + S_x_lcm_ab << "\n";

  return 0;
}