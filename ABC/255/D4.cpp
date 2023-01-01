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

  int n, q;
  cin >> n >> q;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(ALL(A));

  vll S(n + 1, 0ll);
  for (int i = 0; i < n; i++) {
    S[i + 1] = S[i] + A[i];
  }

  // for (int i = 0; i < n; i++) {
  //   cout << A[i] << " ";
  // }
  // cout << "\n";

  // for (int i = 0; i < n; i++) {
  //   cout << S[i] << " ";
  // }
  // cout << "\n";

  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    int idx_x = distance(A.begin(), lower_bound(ALL(A), x));
    // cout << idx_x << "\n";
    ll lower_sum = x * (ll)idx_x - S[idx_x];
    ll upper_sum = (S[n] - S[idx_x]) - x * (ll)(n - idx_x);
    // cout << lower_sum << " " << upper_sum << '\n';
    cout << lower_sum + upper_sum << '\n';
  }
  return 0;
}