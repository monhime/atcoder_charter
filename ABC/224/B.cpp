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
  int h, w;
  cin >> h >> w;
  vvll A(h, vll(w));
  REP(i, h) {
    REP(j, w) { cin >> A[i][j]; }
  }
  REP(i_1, h - 1) {
    FOR(i_2, i_1 + 1, h) {
      REP(j_1, w - 1) {
        FOR(j_2, j_1 + 1, w) {
          if (A[i_1][j_1] + A[i_2][j_2] > A[i_1][j_2] + A[i_2][j_1]) {
            cout << "No\n";
            return 0;
          }
        }
      }
    }
  }
  cout << "Yes\n";
  return 0;
}
