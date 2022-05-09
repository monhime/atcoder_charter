#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'
using ll = long long;
constexpr long long infll = 1LL << 62;
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::map<int, std::set<int>> map_X;  // 色iがどの座標にあるか
  int x, c;
  for (int i = 0; i < n; i++) {
    std::cin >> x >> c;
    map_X[c].emplace(x);
  }
  int color_size = map_X.size();
  int color = 0;
  std::vector<std::vector<ll>> dp(color_size + 1, std::vector<ll>(2, infll));
  dp[0][0] = 0ll;
  dp[0][1] = 0ll;
  ll pre_left = 0ll, pre_right = 0ll;

  for (auto& X : map_X) {
    color++;
    ll left = *X.second.begin();
    ll right = *X.second.rbegin();
    // →右
    for (int i = 0; i < 2; i++) {
      ll pre_x = (i ? pre_right : pre_left);

      if (left < pre_x) {
        chmin(dp[color][1],
              dp[color - 1][i] + (ll)(right - left + pre_x - left));
      } else {
        chmin(dp[color][1], dp[color - 1][i] + (ll)(right - pre_x));
      }
    }
    // →左
    for (int i = 0; i < 2; i++) {
      ll pre_x = (i ? pre_right : pre_left);

      if (pre_x < right) {
        chmin(dp[color][0],
              dp[color - 1][i] + (ll)(right - left + right - pre_x));
      } else {
        chmin(dp[color][0], dp[color - 1][i] + (ll)(pre_x - left));
      }
    }
    pre_right = right;
    pre_left = left;
  }

  std::cout << std::min(dp[color_size][0] + abs(pre_left),
                        dp[color_size][1] + abs(pre_right))
            << "\n";

  return 0;
}
