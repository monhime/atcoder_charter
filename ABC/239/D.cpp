#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};
using ll = long long;
template <class T>
bool is_prime(T num) {
  if (num < 2)
    return false;
  else if (num == 2)
    return true;
  else if (num % 2 == 0)
    return false;

  for (T i = 3; i * i <= num; i += 2) {
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  bool not_prime = true;  //高橋君が勝てる整数がある
  FOR(i, a, b + 1) {
    bool flag = false;
    FOR(j, c, d + 1) {
      if (flag = is_prime(i + j)) {
        break;
      }
    }
    if (!flag) {
      cout << "Takahashi\n";
      return 0;
    }
  }
  cout << "Aoki\n";

  //   int len_pf = (d + b) - (c + a) + 1;
  //   vector<bool> Prime_flag(len_pf, false);
  //   //範囲：a + c 〜　b + d
  //   REP(i, len_pf) {
  //     if (!is_prime((a + c) + i)) {
  //       Prime_flag[i] = true;
  //     }
  //   }

  return 0;
}
