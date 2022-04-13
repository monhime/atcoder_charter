#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
using ll = long long;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, n;
  cin >> n;
  unordered_map<int, int> map_A;

  REP(i, 4 * n - 1) {
    cin >> a;
    map_A[a] += 1;
  }

  vector<pair<int, int>> v_pair_A;
  for (auto& m_p : map_A) {
    v_pair_A.emplace_back(make_pair(m_p.second, m_p.first));
  }
  sort(ALL(v_pair_A));
  cout << v_pair_A[0].second << "\n";

  return 0;
}
