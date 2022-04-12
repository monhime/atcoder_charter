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
  int n;
  cin >> n;
  vi G(n);
  int a, b;
  REP(i, n - 1) {
    cin >> a >> b;
    a -= 1;
    b -= 1;
    G[a]++;
    G[b]++;
  }
  int cunt_1 = 0;
  int cunt_par = 0;
  for (int& g : G) {
    if (g == 1) {
      cunt_1++;
    } else if (g == n - 1) {
      cunt_par++;
    } else {
      cout << "No\n";
      return 0;
    }
  }
  if ((cunt_1 == n - 1) && (cunt_par == 1)) {
    cout << "Yes\n";
    return 0;
  }
  return 0;
}
