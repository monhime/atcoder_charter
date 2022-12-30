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

  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();

  int left = 0;
  int right = 0;
  int sum_dot = 0;  //[left, right)の.の個数
  int ans = 0;
  while (left < n) {
    while (right <= n && sum_dot <= k) {
      //   cout << left << " " << right << " " << sum_dot << "\n";
      ans = max(ans, right - left);

      if (s[right] == '.') {
        sum_dot++;
      }

      right++;
    }
    if (s[left] == '.') {
      sum_dot--;
    }
    left++;
  }
  cout << ans << "\n";

  return 0;
}