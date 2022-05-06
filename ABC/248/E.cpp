#include <iostream>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, k;
  std::cin >> n >> k;
  if (k == 1) {
    std::cout << "Infinity\n";
    return 0;
  }
  std::vector<std::pair<ll, ll>> XY(n);
  for (int i = 0; i < n; i++) {
    std::cin >> XY[i].first >> XY[i].second;
  }
  if (n == 2) {
    // 同時に、k==2
    std::cout << 1 << "\n";
    return 0;
  }
  std::vector<int> List;
  std::vector<std::vector<bool>> Flag(
      n, std::vector<bool>(n, true));  //上三角しか使わない
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ll x_i = XY[i].first, y_i = XY[i].second;
    for (int j = i + 1; j < n; j++) {
      if (!Flag[i][j]) {  //すでに同じ直線を見た
        continue;
      }
      ll x_j = XY[j].first, y_j = XY[j].second;
      int cunt = 2;  // 点iと点jの直線上にある点の数
      List.clear();
      List.emplace_back(i);
      List.emplace_back(j);
      for (int k = j + 1; k < n; k++) {
        ll x_k = XY[k].first, y_k = XY[k].second;
        // (yi - yj)/(xi - xj) = (yk - yj)/(xk - xj)
        if ((y_i - y_j) * (x_k - x_j) == (y_k - y_j) * (x_i - x_j)) {
          cunt++;
          List.emplace_back(k);
        }
      }
      for (int i = 0; i < cunt - 1; i++) {
        for (int j = i + 1; j < cunt; j++) {
          Flag[List[i]][List[j]] = false;
        }
      }

      if (cunt >= k) {
        ans++;
      }
    }
  }
  std::cout << ans << "\n";

  return 0;
}
