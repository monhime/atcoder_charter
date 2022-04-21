#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // -1 <= k <= 2で(3 + k, 2 + k): (2, 1), (3, 2), (4, 3), (5, 4)
  // -2 <= k <= 1で(3 + k, 2 - k): (1, 4), (2, 3), (3, 2), (4, 1)
  // マス内の(a, b)を中止とするx
  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;  //左上(p, r), 右下 (q, s)
  for (ll y = p; y <= q; y++) {
    string ans = "";
    for (ll x = r; x <= s; x++) {
      if ((y - a) == (x - b) || (y - a) == -(x - b)) {
        ans += "#";
      } else {
        ans += ".";
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
