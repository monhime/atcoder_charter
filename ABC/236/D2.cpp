#include <iostream>
#include <map>
#include <vector>
void dfs(int kumi, int ans_tmp, int &ans, std::map<int, bool> &map_nokori,
         const int &n, const std::vector<std::vector<int>> &A) {
  if (kumi == n) {
    ans = std::max(ans_tmp, ans);
    return;
  }
  int a = -1;
  for (auto itr = map_nokori.begin(); itr != map_nokori.end(); ++itr) {
    if (a == -1 && itr->second) {
      a = itr->first;
      itr->second = false;
    } else if (itr->second) {
      itr->second = false;
      dfs(kumi + 1, ans_tmp ^ A[a][itr->first - 1 - a], ans, map_nokori, n, A);
      itr->second = true;
    }
  }
  map_nokori[a] = true;
  return;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, a;
  std::cin >> n;
  std::vector<std::vector<int>> A(2 * n - 1);
  for (int i = 0; i < 2 * n - 1; i++) {
    for (int j = 0; j < 2 * n - 1 - i; j++) {
      std::cin >> a;
      A[i].emplace_back(a);
    }
  }

  std::map<int, bool> map_nokori;
  for (int i = 0; i < 2 * n; i++) {
    map_nokori[i] = true;
  }
  int ans = 0;
  dfs(0, 0, ans, map_nokori, n, A);
  std::cout << ans << "\n";
  return 0;
}
