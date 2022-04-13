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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s, t;
  cin >> s >> t;

  int len_s = s.length();
  int alphabet = 'z' - 'a' + 1;
  int k;
  //   debug(alphabet);
  if (t[0] >= s[0]) {
    k = t[0] - s[0];
  } else {
    k = t[0] + alphabet - s[0];
  }
  //   debug(k);
  REP(i, len_s) {
    if (((t[i] >= s[i]) && (k == t[i] - s[i])) ||
        ((t[i] < s[i]) && (k == t[i] + alphabet - s[i]))) {
      continue;
    }
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";

  return 0;
}
