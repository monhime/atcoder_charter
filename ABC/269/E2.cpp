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
using vvi = vector<vector<int>>;
using vll = vector<ll>;

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
  //   cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;

  // 目標の
  int left = 0;
  int right = n;
  while (right - left > 1) {
    int m = (left + right) / 2;
    if () {
      // [m, n)に目標があるとき
      left = m;
    } else {
      // [0, m)に目標があるとき
      right = m;
    }
  }

  cout << "! " << a + 1 << " " << c + 1 << "\n";
  return 0;
}