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

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  ll l, r;
  cin >> n >> l >> r;

  vll dp_l(n + 1);
  vll A(n);
  ll sum_A = 0ll;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum_A += A[i];
  }
  dp_l[0] = sum_A;
  for (int i = 1; i <= n; i++) {
    dp_l[i] = dp_l[i - 1] - (A[i - 1] - l);
  }
  for (int i = 0; i <= n; i++) {
    cout << dp_l[i] << " ";
  }
  cout << "\n";

  // lで埋める範囲の右側(1-idx)
  int l_idx = distance(dp_l.begin(), min_element(ALL(dp_l)));
  //   debug(l_idx);
  for (int i = 0; i < l_idx; i++) {
    A[i] = l;
  }

  for (int i = 0; i < n; i++) {
    cout << A[i] << " ";
  }
  cout << "\n";

  vll dp_r(n + 1);
  dp_r[0] = dp_l[l_idx];
  for (int i = 1; i <= n; i++) {
    dp_r[i] = dp_r[i - 1] - (A[n - i] - r);
  }
  for (int i = 0; i <= n; i++) {
    cout << dp_r[i] << " ";
  }
  cout << "\n";
  cout << *min_element(ALL(dp_r)) << "\n";

  return 0;
}