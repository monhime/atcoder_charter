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

  int n, m;
  cin >> n >> m;
  ll Sum = 0ll;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  ll sum = 0ll;    // 部分列の重み付き和
  ll sigma = 0ll;  // 部分列の輪
  for (int i = 0; i < m; i++) {
    sum += (i + 1) * A[i];
    sigma += A[i];
  }

  ll ans = sum;

  for (int i = 0; i < n - m; i++) {
    // S[1] = 1*A1 + 2*A2 → S[2] = 1*A2 + 2*A3
    // S[2] = S[1] - (A1 + A2) + 2*A3
    // S[i] = S[i - 1] - sigma(1, 3) + m * A[]
    sum -= sigma;
    sum += m * A[i + m];
    ans = max(ans, sum);
    sigma -= A[i];
    sigma += A[i + m];
  }
  cout << ans << "\n";

  return 0;
}