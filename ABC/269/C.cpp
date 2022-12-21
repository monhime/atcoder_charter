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
string sinsu(T n, int k) {
  string bi = "";
  while (n != 0) {  // llなら0llへ
    bi += to_string(n % abs(k));
    if (k < 0)
      n = -(-n / k);
    else
      n /= k;
  }
  string bi_r(bi.rbegin(), bi.rend());
  return bi_r;
}

int main() {
  ll n;
  cin >> n;

  vector<ll> flag_1;
  ll base_2 = 1ll;
  for (int i = 0; i < 60; i++) {
    if (n % 2ll) {
      flag_1.emplace_back(base_2);
    }
    base_2 *= 2ll;
    n /= 2ll;
  }

  int len_1 = flag_1.size();
  for (int tmp = 0; tmp < (1 << len_1); tmp++) {
    ll ans = 0ll;
    bitset<15> s(tmp);  // bit列の長さを予め数字で記入
    for (int i = 0; i < len_1; i++) {
      if (s.test(i)) {  // i bit目が1なら
        ans += flag_1[i];
      }
    }
    cout << ans << "\n";
  }

  return 0;
}