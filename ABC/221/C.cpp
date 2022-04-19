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

  string nx;
  cin >> nx;
  int left, right;  //抜き出す区間
  int len_n = nx.length();
  vector<char> c_n(len_n);
  REP(i, len_n) { c_n[i] = nx[i]; }
  sort(ALL(c_n), greater<char>());
  string n(c_n.begin(), c_n.end());  //降順文字列
  string ans1, ans2;
  ans1 = "";
  ans2 = "";
  REP(i, len_n / 2) {
    ans1 += n[2 * i];
    ans2 += n[2 * i + 1];
  }
  if (len_n % 2 == 1) {
    if (stoll(ans1 + n.back()) * stoll(ans2) >
        stoll(ans1) * stoll(ans2 + n.back())) {
      ans1 += n.back();
    } else {
      ans2 += n.back();
    }
  }
  cout << stoll(ans1) * stoll(ans2) << "\n";

  return 0;
}
