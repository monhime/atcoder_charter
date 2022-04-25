#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;
template <class T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int ans = n * (n - 1) / 2;
  vector<pair<int, int>> XY(n);
  for (int i = 0; i < n; i++) {
    cin >> XY[i].first >> XY[i].second;
  }
  set<pair<int, int>> set_dXY;
  for (int i = 0; i < n - 1; i++) {
    int x_i = XY[i].first;
    int y_i = XY[i].second;
    for (int j = i + 1; j < n; j++) {
      int dx = XY[j].first - x_i;
      int dy = XY[j].second - y_i;
      int gcd_dxy = gcd(abs(dx), abs(dy));
      dx /= gcd_dxy;
      dy /= gcd_dxy;
      set_dXY.emplace(make_pair(dx, dy));
      set_dXY.emplace(make_pair(-dx, -dy));
    }
  }
  cout << set_dXY.size() << "\n";

  return 0;
}
