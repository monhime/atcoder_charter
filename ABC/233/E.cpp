#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string x;  // max 5e5桁
  cin >> x;
  int len_x = x.length();

  // 右に0、1、2、...、1e2桁ずらして足した値？
  // 0桁目:0 ~ 桁の和の1の位、繰り上がり分n
  // 1桁目:n + 1~桁の和の1の位、繰り返り分n
  int sum_x = 0;
  for (auto &nx : x) {
    sum_x += nx - '0';
  }
  int n = 0;
  string ans = "";
  for (int i = x.length() - 1;; i--) {
    n += sum_x;
    ans.push_back('0' + n % 10);
    n /= 10;
    if (i >= 0) {
      sum_x -= x[i] - '0';
    }
    if (n == 0 && i <= 0) {
      break;
    }
  }
  reverse(ans.rbegin(), ans.rend());
  cout << ans << "\n";
  return 0;
}
