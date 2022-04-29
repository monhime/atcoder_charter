#include <iostream>
#include <string>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s, z;
  z = "ZONe";
  std::cin >> s;
  int ans = 0;
  for (int i = 0; i < 9; i++) {
    bool IsSame = true;
    for (int j = 0; j < 4; j++) {
      if (s[i + j] != z[j]) {
        IsSame = false;
        break;
      }
    }
    if (IsSame) {
      ans++;
    }
  }
  std::cout << ans << "\n";

  return 0;
}
