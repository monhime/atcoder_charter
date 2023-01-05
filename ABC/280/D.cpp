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
void prime_factorize(T N, map<ll, int>& map_P) {
  for (T a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    int ex = 0;
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    map_P[a] = ex;
  }
  if (N != 1) map_P[N] = 1ll;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  ll k;
  cin >> k;
  map<ll, int> map_Fact;
  ll ans = 0ll;

  prime_factorize(k, map_Fact);

  for (auto mpFact : map_Fact) {
    // 各素因数p_iに対し，p_i^a_i <= n!となるような最小のnを求める
    // nはp_iの倍数，n!の素因数p_iの個数 = (n-p_i)!の素因数p_iの個数 +
    // nの素因数p_iの個数
    // 0からp_iを加えながらその値がp_iの何乗かカウント（総和がa_i以上となるまで）
    ll p_i = mpFact.first;
    int a_i = mpFact.second;

    ll n = 0ll;
    int sisu = 0;  // n!はp_iの何乗か
    while (sisu < a_i) {
      n += p_i;

      int cunt = 0;  // n が p_i の何乗か
      ll _n = n;
      while (_n % p_i == 0ll) {
        _n /= p_i;
        cunt++;
      }
      // nにある素因数p_iの個数を追加
      sisu += cunt;
      //   cout << cunt << " " << sisu << "\n";
    }
    chmax(ans, n);
  }

  cout << ans << "\n";

  return 0;
}