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
  cin >> n;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  sort(ALL(A), greater<ll>());
  ll ans = -1ll;
  if (A[0] % 2) {
    for (int j = 1; j < n; j++) {
      if (A[j] % 2) {
        ans = A[0] + A[j];
        break;
      }
    }
    for (int i = 1; i < n - 1; i++) {
      if (A[i] % 2) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (A[j] % 2 == 0) {
          ans = max(ans, A[i] + A[j]);
          break;
        }
      }
      break;
    }
  } else {  // A[0]は偶数
    for (int j = 1; j < n; j++) {
      if (A[j] % 2 == 0) {
        ans = A[0] + A[j];
        break;
      }
    }
    for (int i = 1; i < n - 1; i++) {
      if (A[i] % 2 == 0) {
        continue;
      }
      for (int j = i + 1; j < n; j++) {
        if (A[j] % 2) {
          ans = max(ans, A[i] + A[j]);
          break;
        }
      }
      break;
    }
  }
  cout << ans << "\n";

  return 0;
}