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

  int n, q;
  cin >> n >> q;
  int a;
  map<int, vector<int>> map_A;
  REP(i, n) {
    cin >> a;
    map_A[a].emplace_back(i);
  }
  int x, k;
  REP(i, q) {
    cin >> x >> k;
    if ((map_A.count(x) == 0) || (map_A[x].size() < k)) {
      cout << "-1\n";
      continue;
    }
    cout << map_A[x][k - 1] + 1 << "\n";
  }

  return 0;
}
