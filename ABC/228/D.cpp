#include <iostream>
#include <map>
#include <vector>
constexpr int N = 1 << 20;
constexpr int MASK = N - 1;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int q;
  std::cin >> q;
  std::vector<int> T(q);
  std::vector<int64_t> X(q), Ans;

  for (int i = 0; i < q; i++) {
    std::cin >> T[i] >> X[i];
  }
  // [l, r) は-1
  std::map<int, int> map_RL;
  std::map<int, int64_t> map_ans;
  map_RL[N] = 0;
  for (int i = 0; i < q; i++) {
    int mod_x = X[i] & MASK;
    if (T[i] == 1) {
      auto itr = map_RL.upper_bound(mod_x);
      if (itr == map_RL.end()) {
        itr = map_RL.begin();
        mod_x = 0;
      }
      if (itr->second <= mod_x) {
        map_ans[mod_x] = X[i];
        int l1 = itr->second, r1 = mod_x, l2 = mod_x + 1, r2 = itr->first;
        map_RL.erase(itr);
        if (l1 < r1) {
          map_RL[r1] = l1;
        }
        if (l2 < r2) {
          map_RL[r2] = l2;
        }
      } else {
        // mod_xの位置が-1でないとき、次の-1の区間の最左端に代入する
        map_ans[itr->second] = X[i];
        //区間の更新
        itr->second += 1;
        if (itr->first == itr->second) {
          map_RL.erase(itr);
        }
      }
    } else {
      if (map_ans.count(mod_x)) {
        Ans.emplace_back(map_ans[mod_x]);

      } else {
        Ans.emplace_back(-1);
      }
    }
  }

  for (auto &a : Ans) {
    std::cout << a << "\n";
  }

  return 0;
}
