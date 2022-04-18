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

  string x;
  cin >> x;
  map<char, char> map_X;
  REP(i, x.length()) { map_X[x[i]] = 'a' + i; }
  int n;
  cin >> n;
  vector<pair<string, string>> S2(n);
  string s, s2;
  REP(i, n) {
    cin >> s;
    s2 = "";
    REP(j, s.length()) { s2 += map_X[s[j]]; }
    S2[i] = make_pair(s2, s);
  }
  sort(ALL(S2));
  REP(i, n) { cout << S2[i].second << "\n"; }

  return 0;
}
