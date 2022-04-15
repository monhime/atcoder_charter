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

  string s;
  cin >> s;
  int len_s = s.length();
  // qwqaaa→qwqでok→aの個数は後ろの方が大きい
  // aaaqwq→ok→aが足りないx
  string new_s;
  int idx_left = -1;
  int idx_right;  //[)
  REP(i, len_s) {
    if (s[i] != 'a') {
      idx_left = i;
      break;
    }
  }
  if (idx_left == -1) {
    cout << "Yes\n";
    return 0;
  }

  REP(i, len_s) {
    if (s[len_s - 1 - i] != 'a') {
      idx_right = len_s - i;
      break;
    }
  }
  int cunt = idx_right - idx_left;
  REP(i, cunt / 2) {
    int left_i = idx_left + i;
    int right_i = idx_right - 1 - i;
    if (s[left_i] != s[right_i]) {
      cout << "No\n";
      return 0;
    }
  }
  if (idx_left <= len_s - idx_right) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
