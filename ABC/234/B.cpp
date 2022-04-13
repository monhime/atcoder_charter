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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Pii> XY(n);
  REP(i, n) {
    int x, y;
    cin >> x >> y;
    XY[i] = make_pair(x, y);
  }
  set<double> Set_kyori;
  REP(i, n - 1) {
    REP(j, n) {
      Set_kyori.insert(
          (XY[i].second - XY[j].second) * (XY[i].second - XY[j].second) +
          (XY[i].first - XY[j].first) * (XY[i].first - XY[j].first));
    }
  }
  printf("%.10f\n", sqrt(*rbegin(Set_kyori)));
  return 0;
}
