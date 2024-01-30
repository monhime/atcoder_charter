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

  string s;
  cin >> s;
  int len_s = s.size();

  bool kaibun_flag;
  for (int len_part = len_s; len_part; len_part--) {
    for (int start = 0; start <= len_s - len_part; start++) {
      kaibun_flag = true;
      for (int i = 0; i < len_part / 2; i++) {
        if (s[start + i] != s[start + len_part - 1 - i]) {
          kaibun_flag = false;
          break;
        }
      }
      if (kaibun_flag) {
        cout << len_part << "\n";
        return 0;
      }
    }
  }

  return 0;
}