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

  ll n, ans_p, ans_q, ans_r;
  cin >> n >> ans_p >> ans_q >> ans_r;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int x, y, z, w;
  x = 0;
  y = 0;
  z = 0;
  w = 0;

  ll sum_p, sum_q, sum_r;
  sum_p = 0ll;
  sum_q = 0ll;
  sum_r = 0ll;

  while (x < n) {
    while (y < n && sum_p <= ans_p) {
      while (z < n && sum_q <= ans_q) {
        while (w <= n && sum_r <= ans_r) {
          if (sum_p == ans_p && sum_q == ans_q && sum_r == ans_r) {
            cout << "Yes\n";
            return 0;
          }
          sum_r += A[w];
          w++;
        }
        sum_r -= A[z];
        sum_q += A[z];
        z++;
      }
      sum_q -= A[y];
      sum_p += A[y];
      y++;
    }
    sum_p -= A[x];
    x++;
  }
  cout << "No\n";

  return 0;
}