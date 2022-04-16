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
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  int p1, p2, p3;
  vector<int> P123(n);
  REP(i, n) {
    cin >> p1 >> p2 >> p3;
    P123[i] = p1 + p2 + p3;
  }
  vector<int> P123_temp = P123;
  sort(ALL(P123_temp), greater<int>());
  int P_k = P123_temp[k - 1];
  REP(i, n) {
    if (P123[i] + 300 >= P_k) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
