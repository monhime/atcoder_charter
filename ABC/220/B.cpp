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
  int k;
  string a, b;
  cin >> k >> a >> b;
  string a_r(a.rbegin(), a.rend());
  string b_r(b.rbegin(), b.rend());
  int l_a = a.length();
  int l_b = b.length();
  ll a_10 = 0ll;
  ll b_10 = 0ll;
  REP(i, l_a) { a_10 += pow(k, i) * (a_r[i] - '0'); }
  REP(i, l_b) { b_10 += pow(k, i) * (b_r[i] - '0'); }
  cout << a_10 * b_10 << "\n";
  return 0;
}
