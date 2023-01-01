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
  //   cin.tie(nullptr);             // インタラクティブ実行不可

  ll n, q;
  cin >> n >> q;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(ALL(A));

  vll S(n, 0ll);
  S[0] = A[0];

  for (int i = 1; i < n; i++) {
    S[i] = S[i - 1] + A[i];
  }

  //   for (int i = 0; i < n; i++) {
  //     cout << A[i] << " ";
  //   }
  //   cout << "\n";

  //   for (int i = 0; i < n; i++) {
  //     cout << S[i] << " ";
  //   }
  //   cout << "\n";

  for (int qq = 0; qq < q; qq++) {
    ll x;
    cin >> x;
    ll idx_upper = (ll)distance(A.begin(), upper_bound(ALL(A), x));
    ll idx_lower = (ll)distance(A.begin(), lower_bound(ALL(A), x));

    ll ans_lower;
    if (idx_lower == 0) {
      ans_lower = 0ll;
    } else {
      ans_lower = x * idx_lower - S[idx_lower - 1];
    }
    ll ans_upper = S[n - 1] - S[idx_upper - 1] - x * (n - idx_upper);

    // cout << idx_lower << " " << idx_upper << "\n";
    // cout << ans_lower << " " << ans_upper << "\n";
    cout << ans_lower + ans_upper << "\n";
  }

  return 0;
}