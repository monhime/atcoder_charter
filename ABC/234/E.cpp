#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 100未満の整数はすべて等差数
  // 111, 123, 135, 147, 159, 210, 222, 234, 257, 321, 333, 345, 357, 369
  // すくない→初めに全列挙？ 各桁差-5から+5までで存在すれば記録
  ll x;
  cin >> x;
  vector<ll> Tosa;
  for (ll i = 1ll; i < 100ll; i++) {
    Tosa.emplace_back(i);
  }
  for (int keta = 3; keta <= to_string(x).length(); keta++) {
    for (int sento = 1; sento < 10; sento++) {
      for (int sa = -5; sa < 6; sa++) {
        string suji;
        int d = sento;
        for (int i = 0; i < keta; i++) {
          if (d < 0 || d > 10) {
            break;
          }
          suji += '0' + d;
          d += sa;
        }
        Tosa.emplace_back(stoll(suji));
      }
    }
  }
  sort(Tosa.begin(), Tosa.end());
  cout << *lower_bound(Tosa.begin(), Tosa.end(), x) << "\n";

  return 0;
}
