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

  int n;
  cin >> n;
  vector<ll> T(n);
  vector<int> K(n);
  vector<vector<int>> A(n);
  int a;
  REP(i, n) {
    cin >> T[i] >> K[i];
    REP(j, K[i]) {
      cin >> a;
      A[i].emplace_back(a - 1);
    }
  }
  // 1->2->4と1->3->4のダブリ
  queue<int> que;
  que.emplace(n - 1);
  vector<bool> visited(n, false);
  visited[n - 1] = true;
  ll ans = T.back();
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto &xnode : A[node]) {
      if (visited[xnode]) {
        continue;
      }
      ans += T[xnode];
      visited[xnode] = true;
      que.emplace(xnode);
    }
  }
  cout << ans << "\n";
  return 0;
}
