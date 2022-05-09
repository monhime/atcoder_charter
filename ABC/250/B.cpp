#include <iostream>
#include <string>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n, a, b;
  std::cin >> n >> a >> b;
  bool left_white = true, white_flag;
  for (int tile_tate = 0; tile_tate < n; tile_tate++) {
    for (int i = 0; i < a; i++) {
      white_flag = left_white;
      for (int tile_yoko = 0; tile_yoko < n; tile_yoko++) {
        for (int j = 0; j < b; j++) {
          std::cout << (white_flag ? "." : "#");
        }
        white_flag ^= true;
      }
      std::cout << "\n";
    }
    left_white ^= true;
  }
  return 0;
}
