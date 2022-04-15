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

  map<string, int> map_S, map_T;
  vector<string> S(3), T(3);
  REP(i, 3) {
    cin >> S[i];
    map_S[S[i]]++;
  }
  REP(i, 3) {
    cin >> T[i];
    map_T[T[i]]++;
  }
  if (map_S.size() != map_T.size()) {
    cout << "No\n";
  } else {
    for (auto &m_s : map_S) {
      if (map_T[m_s.first] != m_s.second) {
        cout << "No\n";
        return 0;
      }
    }
    if (map_S.size() <=
        2) {  // 1種類は当然、2種類は合って無くても2回目以降は2つあるのを交換歯痛付ける
      cout << "Yes\n";
    } else {  // 3種類あるとき
      int tigai = 0;
      REP(i, 3) {
        if (S[i] != T[i]) {
          tigai++;
        }
      }
      if ((tigai == 0) || (tigai == 3)) {  // 1はありえない、3は偶数回で合う
        cout << "Yes\n";
      } else {
        cout << "No\n";
      }
    }
  }

  return 0;
}
