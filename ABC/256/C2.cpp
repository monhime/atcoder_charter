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

  int h1, h2, h3, w1, w2, w3;
  cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;
  int ans = 0;
  int lb, mb, rm, ru;
  for (int lu = 1; lu <= w1 - 2; lu++) {
    for (int lm = 1; lm <= w1 - lu - 1; lm++) {
      lb = w1 - lu - lm;
      for (int mu = 1; mu <= min(w2 - 2, h1 - lu - 1); mu++) {
        ru = h1 - lu - mu;
        for (int mm = 1; mm <= min(w2 - mu - 1, h2 - lm - 1); mm++) {
          mb = w2 - mu - mm;
          rm = h2 - lm - mm;
          if (w3 - ru - rm == h3 - lb - mb && h3 - lb - mb >= 1) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << "\n";

  return 0;
}