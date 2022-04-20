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

  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> AB(n);
  REP(i, n) { cin >> AB[i].first >> AB[i].second; }
  map<int, int> map_X;
  map_X[0] = 1;
  int a, b;
  REP(i, n) {
    map<int, int> map_X_tmp;
    tie(a, b) = AB[i];
    for (auto &m_p : map_X) {
      map_X_tmp[m_p.first + a] += m_p.second;
      map_X_tmp[m_p.first + b] += m_p.second;
    }
    map_X = map_X_tmp;
  }
  if (map_X.count(x)) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
