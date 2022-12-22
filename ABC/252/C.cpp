#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;

template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  vector<string> S(n);

  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  int ans = 10000;
  for (int i = 0; i < 10; i++) {
    priority_queue<int> pQ;
    for (int j = 0; j < n; j++) {
      // j番目の文字列で文字iがどこにあるか
      pQ.emplace(-S[j].find(char('0' + i)));
    }
    int pre = -1;
    int time = 0;
    while (!pQ.empty()) {
      int cur = -pQ.top();
      pQ.pop();
      if (cur == pre) {
        pQ.emplace(-(cur + 10));
        continue;
      }
      time = cur;
      pre = cur;
    }
    ans = min(ans, time);
  }
  cout << ans << "\n";

  return 0;
}