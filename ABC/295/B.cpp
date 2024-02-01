#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;

template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int r, c;
  cin >> r >> c;
  vector<string> B(r);
  for (int i = 0; i < r; i++) {
    cin >> B[i];
  }

  for (int y = 0; y < r; y++) {
    for (int x = 0; x < c; x++) {
      //   debug(y);
      //   debug(x);
      if (B[y][x] == '#') {
        bool bomb_flag = false;
        for (int yy = -9; yy <= 9; yy++) {
          if (y + yy < 0 || y + yy >= r) {
            continue;
          }

          for (int xx = -9 + abs(yy); xx <= 9 - abs(yy); xx++) {
            if (x + xx < 0 || x + xx >= c || B[y + yy][x + xx] == '.' ||
                B[y + yy][x + xx] == '#') {
              continue;
            }
            if (B[y + yy][x + xx] - '0' >= abs(xx) + abs(yy)) {
              //   debug(y + yy);
              //   debug(x + xx);
              B[y][x] = '.';
              bomb_flag = true;
              break;
            }
          }
          if (bomb_flag) {
            break;
          }
        }
      }
    }
  }

  for (int y = 0; y < r; y++) {
    for (int x = 0; x < c; x++) {
      if (B[y][x] != '#' && B[y][x] != '.') {
        cout << ".";
      } else {
        cout << B[y][x];
      }
    }
    cout << "\n";
  }

  return 0;
}