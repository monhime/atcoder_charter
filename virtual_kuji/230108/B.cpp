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
  cin >> n;
  vll A(n + 1), B(n);
  ll sum_A = 0ll;
  for (int i = 0; i <= n; i++) {
    cin >> A[i];
    sum_A += A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    ll break_next = min(A[i + 1], B[i]);

    A[i + 1] -= break_next;
    B[i] -= break_next;

    if (B[i] == 0ll) {
      continue;
    }
    A[i] -= min(A[i], B[i]);
  }

  for (int i = 0; i < n + 1; i++) {
    sum_A -= A[i];
  }
  cout << sum_A << "\n";

  return 0;
}