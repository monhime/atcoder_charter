#include <bits/stdc++.h>
using namespace std;
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
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;

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
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  string s;
  cin >> s;
  int len_s = s.size();
  int _tmp = len_s;

  ll ans = 0ll;
  ll keta = 1ll;
  for (int i = 0; i < len_s - 1; i++) {
    keta *= 26ll;
    ans += keta;
    // debug(ans);
  }
  for (int i = 0; i < len_s; i++) {
    ans += keta * (ll)(s[i] - 'A');
    keta /= 26ll;
    // debug(ans);
  }
  cout << ans + 1 << "\n";

  return 0;
}