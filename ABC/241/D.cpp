#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int q;
  std::cin >> q;
  std::vector<int64_t> Ans;
  std::multiset<int64_t> mSet;
  for (int qq = 0; qq < q; qq++) {
    int flag, k;
    int64_t x;
    std::cin >> flag;
    std::cin >> x;
    if (flag == 1) {
      mSet.emplace(x);
    } else if (flag == 2) {
      std::cin >> k;
      auto s = mSet.upper_bound(x);  //目標+1を指す
      k--;
      while (s != mSet.begin() && k--) {  // begin()指したらout、
        s--;
      }
      if (s == mSet.begin()) {
        Ans.emplace_back(-1LL);
      } else {
        s--;
        Ans.emplace_back(*s);
      }
    } else {
      std::cin >> k;
      auto s = mSet.lower_bound(x);
      k--;
      while (s != mSet.end() && k--) {
        s++;
      }
      if (s != mSet.end()) {
        Ans.emplace_back(*s);
      } else {
        Ans.emplace_back(-1);
      }
    }
  }
  for (int i = 0; i < Ans.size(); i++) {
    std::cout << Ans[i] << "\n";
  }

  return 0;
}
