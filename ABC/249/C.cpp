#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<string> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  int ans = 0;
  for (int tmp = 0; tmp < 1 << 15; tmp++) {
    bitset<15> s(tmp);  // bit列の長さを予め数字で記入
    map<char, int> map_S;
    for (int i = 0; i < n; i++) {
      if (s.test(i)) {  // i bit目が1なら
        for (auto &c : S[i]) {
          map_S[c]++;
        }
      }
    }
    int ans_tmp = 0;
    for (auto &m_p : map_S) {
      if (m_p.second == k) {
        ans_tmp++;
      }
    }
    ans = max(ans, ans_tmp);
  }
  cout << ans << "\n";

  return 0;
}
