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

int zyanken(const char &a, const char &b) {
  if ((a == 'G' && b == 'C') || (a == 'C' && b == 'P') ||
      (a == 'P' && b == 'G')) {
    return 1;
  } else if (a == b) {
    return 0;
  } else {
    return -1;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<string> S(2 * n);
  vector<pair<int, int>> pA(2 * n);  // 勝利数、-idx
  REP(i, 2 * n) {
    cin >> S[i];
    pA[i] = make_pair(0, -i);
  }
  int idx_a, idx_b;
  REP(round, m) {
    REP(i, n) {
      idx_a = -pA[2 * i].second;
      idx_b = -pA[2 * i + 1].second;
      if (zyanken(S[idx_a][round], S[idx_b][round]) == 1) {
        pA[2 * i].first++;
      } else if (zyanken(S[idx_a][round], S[idx_b][round]) == -1) {
        pA[2 * i + 1].first++;
      }
      sort(ALL(pA), greater<pair<int, int>>());
    }
  }
  REP(i, 2 * n) { cout << -pA[i].second + 1 << "\n"; }
  return 0;
}
