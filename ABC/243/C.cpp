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
  vector<tuple<int, int, int>> YXi(n);
  REP(i, n) {
    cin >> get<1>(YXi[i]) >> get<0>(YXi[i]);
    get<2>(YXi[i]) = i;
  }
  sort(ALL(YXi));
  string s;
  cin >> s;
  int cur_y = -1;
  bool right_flag;
  REP(i, n) {
    int idx = get<2>(YXi[i]);
    if (cur_y != get<0>(YXi[i])) {  //新しいy
      cur_y = get<0>(YXi[i]);
      right_flag = s[idx] == 'R';
    } else {
      if (right_flag && s[idx] == 'L') {
        cout << "Yes\n";
        return 0;
      }
      right_flag = right_flag || s[idx] == 'R';
    }
  }
  cout << "No\n";

  return 0;
}
