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
  int n, m;
  cin >> n >> m;
  int k, x;

  vector<vector<bool>> XX(n, vector<bool>(n, false));
  for (int i = 0; i < m; i++) {
    cin >> k;
    vi X(k);
    for (int j = 0; j < k; j++) {
      cin >> x;
      X[j] = x - 1;
    }

    for (int i = 0; i < k - 1; i++) {
      for (int j = i + 1; j < k; j++) {
        XX[X[i]][X[j]] = true;
        XX[X[j]][X[i]] = true;
      }
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (!XX[i][j]) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";

  return 0;
}