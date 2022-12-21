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

int n, m;

void f(int keta, int min_a, vi& A) {
  if (keta == n) {
    for (int i = 0; i < n; i++) {
      cout << A[i] << " ";
    }
    cout << "\n";
  } else {
    for (int i = min_a; i <= m; i++) {
      // cout << keta << " " << min_a << "\n";
      A[keta] = i;
      f(keta + 1, i + 1, A);
    }
  }
}

int main() {
  cin >> n >> m;
  vi A(n);
  f(0, 1, A);

  return 0;
}