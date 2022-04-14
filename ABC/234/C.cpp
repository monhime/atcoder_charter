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
template <class T>
string sinsu(T n, int k) {
  string bi = "";
  while (n != 0ll) {
    bi += to_string(n % abs(k) * 2);
    if (k < 0)
      n = -(-n / k);
    else
      n /= k;
  }
  string bi_r(bi.rbegin(), bi.rend());
  return bi_r;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k;
  cin >> k;
  cout << sinsu(k, 2) << "\n";

  return 0;
}
