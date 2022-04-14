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
  vector<int> A(n), B(n);
  unordered_map<int, int> map_A;
  unordered_map<int, int> map_B;
  int a, b;
  REP(i, n) {
    cin >> a;
    A[i] = a;
    map_A[a]++;
  }
  REP(i, n) {
    cin >> b;
    B[i] = b;
    map_B[b]++;
  }
  unordered_map<int, int> map_AB;
  for (auto &m_a : map_A) {
    int m_a_k = m_a.first;
    if (map_B[m_a_k]) {
      map_AB[m_a_k] = min(map_A[m_a_k], map_B[m_a_k]);
    }
  }

  int ans_1 = 0;
  REP(i, n) {
    if (A[i] == B[i]) {
      ans_1++;
      map_AB[A[i]]--;
    }
  }
  cout << ans_1 << "\n";
  int ans_2 = 0;

  for (auto &m_ab : map_AB) {
    ans_2 += m_ab.second;
  }
  cout << ans_2 << "\n";
  return 0;
}
