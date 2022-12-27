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
template <class T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
template <class T>
T gcd_vec(vector<T> const& A) {
  T ret = A[0];
  REP(i, A.size() - 1)
  ret = gcd(ret, A[i + 1]);
  return ret;
}

template <class T>
void prime_factorize(T N, map<int, int>& map_P) {
  for (T a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    int ex = 0;
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    map_P[a] = ex;
  }
  if (N != 1) map_P[N] = 1;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  vi A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  int gcd_a = gcd_vec(A);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x = A[i] / gcd_a;
    map<int, int> map_P;
    prime_factorize(x, map_P);
    for (auto& m_p : map_P) {
      if (m_p.first > 3) {
        cout << "-1\n";
        return 0;
      }
      ans += m_p.second;
    }
  }
  cout << ans << "\n";

  return 0;
}