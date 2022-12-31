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

  int n;

  ll x;
  cin >> n >> x;
  string s;
  cin >> s;

  deque<int> dQ;
  for (int i = 0; i < n; i++) {
    char c = s[i];
    if (c == 'U' && !dQ.empty() && ((dQ.back() == 'R') || (dQ.back() == 'L'))) {
      dQ.pop_back();
    } else {
      dQ.emplace_back(c);
    }
  }
  ll ans = x;
  while (!dQ.empty()) {
    char c = dQ.front();
    dQ.pop_front();
    if (c == 'U') {
      ans /= 2ll;
    } else if (c == 'L') {
      ans *= 2ll;
    } else {
      ans = 2ll * ans + 1ll;
    }
  }
  cout << ans << "\n";

  return 0;
}