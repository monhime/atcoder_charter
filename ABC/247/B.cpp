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
  unordered_map<string, int> map_ST;
  vector<string> S(n), T(n);
  REP(i, n) {
    cin >> S[i] >> T[i];
    map_ST[S[i]]++;
    map_ST[T[i]]++;
  }
  REP(i, n) {
    if (((S[i] != T[i]) && (map_ST[S[i]] > 1 and map_ST[T[i]] > 1)) ||
        ((S[i] == T[i]) && (map_ST[S[i]] > 2))) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}
