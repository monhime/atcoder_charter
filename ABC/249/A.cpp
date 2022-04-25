#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, d, e, f, x;
  cin >> a >> b >> c >> d >> e >> f >> x;
  int takahashi = x / (a + c) * a * b + min(x % (a + c), a) * b;
  int aoki = x / (d + f) * d * e + min(x % (d + f), d) * e;
  if (takahashi > aoki) {
    cout << "Takahashi\n";
  } else if (takahashi < aoki) {
    cout << "Aoki\n";
  } else {
    cout << "Draw\n";
  }

  return 0;
}
