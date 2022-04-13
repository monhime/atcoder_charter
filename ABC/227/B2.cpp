#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pill = pair<int, ll>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

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
int S(const int& a, const int& b) { return 4 * a * b + 3 * a + 3 * b; }

int main() {
  int n;
  cin >> n;
  set<int> Set;
  int temp_s;
  FOR(a, 1, 140) {
    FOR(b, 1, 140) {
      temp_s = S(a, b);
      if (temp_s > 1000) {
        continue;
      }
      Set.insert(temp_s);
    }
  }
  int ans = 0;
  int s;
  REP(i, n) {
    cin >> s;
    if (Set.count(s) == 0) {
      ans++;
    }
  }
  cout << ans << "\n";
  return 0;
}
