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

  string n;
  cin >> n;
  int len_n = n.length();
  vector<char> ans1, ans2;
  ll ans = 0ll;
  REP(tmp, 1 << len_n) {
    bitset<10> s(tmp);  // bit列の長さを予め数字で記入
    ans1 = {};
    ans2 = {};
    REP(i, len_n) {
      if (s.test(i)) {  // i bit目が1なら
        ans1.emplace_back(n[i]);
      } else {
        ans2.emplace_back(n[i]);
      }
    }
    if (!ans1.size() || !ans2.size()) {
      continue;
    }
    sort(ALL(ans1), greater<char>());
    sort(ALL(ans2), greater<char>());
    string ans1s(ALL(ans1));
    string ans2s(ALL(ans2));
    ans = max(ans, stoll(ans1s) * stoll(ans2s));
  }
  cout << ans << "\n";

  return 0;
}
