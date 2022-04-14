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

int main() {
  //   ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int aoki;
  set<int> S;
  while (true) {
    FOR(i, 1, 2 * n + 2) {
      if (!S.count(i)) {
        cout << i << "\n";
        S.emplace(i);
        break;
      }
    }
    cin >> aoki;
    if (aoki == 0) {
      return 0;
    }
    S.emplace(aoki);
  }

  return 0;
}
