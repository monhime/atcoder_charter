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
  int n;
  ll t;
  cin >> n >> t;
  vll A(n), accum_A(n, 0ll);
  ll sum_a = 0ll;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum_a += A[i];
    accum_A[i] = sum_a;
  }
  t %= sum_a;
  auto iter = lower_bound(ALL(accum_A), t);
  int idx = distance(accum_A.begin(), iter);

  cout << idx + 1 << " ";
  if (idx == 0) {
    cout << t << "\n";
  } else {
    iter--;
    cout << t - *iter << "\n";
  }
  return 0;
}