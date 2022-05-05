#include <iostream>
#include <map>
#include <vector>
#define debug(x) std::cerr << #x << ": " << x << '\n'

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  long long n, k;
  std::cin >> n >> k;
  std::vector<long long> A(n);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }
  int loop_cunt = 0;
  long long sum_ame = 0LL;
  std::map<int, long long> map_sum;
  std::map<int, int> map_cunt;
  int sum_ame_modn = sum_ame % n;
  while (loop_cunt < k) {
    sum_ame += A[sum_ame_modn];
    loop_cunt++;
    sum_ame_modn = sum_ame % n;
    if (map_sum.count(sum_ame_modn)) {
      break;  //すでに同じあまりを見つけている（2回目足したあと）
    }
    map_sum[sum_ame_modn] = sum_ame;
    map_cunt[sum_ame_modn] = loop_cunt;
  }
  if (loop_cunt == k) {
    std::cout << sum_ame << "\n";
  } else {
    int loop_start = map_cunt[sum_ame_modn];
    int loop_lap = loop_cunt - loop_start;
    long long ans = map_sum[sum_ame_modn];  //　まずループ開始直前
    ans += (sum_ame - ans) * ((k - loop_start) / loop_lap);  //ループ分
    k -= loop_start + (k - loop_start) / loop_lap * loop_lap;
    while (k--) {
      ans += A[sum_ame_modn];
      sum_ame_modn = ans % n;
    }
    std::cout << ans << "\n";
  }

  return 0;
}
