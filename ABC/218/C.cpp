#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int n;
  std::cin >> n;
  std::vector<std::string> S(n), T(n);
  for (int i = 0; i < n; i++) {
    std::cin >> S[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> T[i];
  }
  // 向き4通り、相対位置200*200に対し、探索200*200
  // 検索に必要な部分だけカット→左上をあわせれば、4*200*200→160000
  int s_left = n - 1, s_right = 0, s_lower = n - 1, s_upper = 0;
  int t_left = n - 1, t_right = 0, t_lower = n - 1, t_upper = 0;
  for (int i = 0; i < n; i++) {
    int left = S[i].find("#");
    if (left == std::string::npos) {
      continue;  //行内"."だけ
    }
    int right = S[i].rfind("#") + 1;
    s_left = std::min(s_left, left);
    s_lower = std::min(s_lower, i);
    s_right = std::max(s_right, right);
    s_upper = std::max(s_upper, i + 1);
  }
  for (int i = 0; i < n; i++) {
    int left = T[i].find("#");
    if (left == std::string::npos) {
      continue;  //行内"."だけ
    }
    int right = T[i].rfind("#") + 1;
    t_left = std::min(t_left, left);
    t_lower = std::min(t_lower, i);
    t_right = std::max(t_right, right);
    t_upper = std::max(t_upper, i + 1);
  }
  int s_tate = s_upper - s_lower;
  int s_yoko = s_right - s_left;
  int t_tate = t_upper - t_lower;
  int t_yoko = t_right - t_left;
  if (!((s_tate == t_tate && s_yoko == t_yoko) ||
        (s_tate == t_yoko && s_yoko == t_tate))) {
    std::cout << "No\n";
    return 0;
  }
  //反転させれば大枠は合っている

  //同じ向き
  if (s_tate == t_tate && s_yoko == t_yoko) {
    for (int i = 0; i < s_tate; i++) {
      for (int j = 0; j < s_yoko; j++) {
        if (S[s_lower + i][s_left + j] != T[t_lower + i][t_left + j]) {
          goto Exit;
        }
      }
    }
    std::cout << "Yes\n";
    return 0;

  Exit:
    // 180
    for (int i = 0; i < s_tate; i++) {
      for (int j = 0; j < s_yoko; j++) {
        if (S[s_lower + i][s_left + j] != T[t_upper - 1 - i][t_right - 1 - j]) {
          goto Exit2;
        }
      }
    }
    std::cout << "Yes\n";
    return 0;
  }
Exit2:
  // t90
  if (s_tate == t_yoko && s_yoko == t_tate) {
    for (int i = 0; i < s_tate; i++) {
      for (int j = 0; j < s_yoko; j++) {
        if (S[s_lower + i][s_left + j] != T[t_upper - 1 - j][t_left + i]) {
          goto Exit3;
        }
      }
    }
    std::cout << "Yes\n";
    return 0;

  Exit3:
    for (int i = 0; i < s_tate; i++) {
      for (int j = 0; j < s_yoko; j++) {
        if (S[s_lower + i][s_left + j] != T[t_lower + j][t_right - 1 - i]) {
          goto Exit4;
        }
      }
    }
    std::cout << "Yes\n";
    return 0;
  }
Exit4:
  std::cout << "No\n";

  return 0;
}
