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

  int a = 0;
  int b = n;
  int c = 0;
  int d = n;
  while (d - c > 1) {
    int m = (c + d) / 2;
    cout << "? " << 1 << " " << n << " " << m + 1 << " " << d << "\n";
    int t;
    cin >> t;
    if (d - m > t)  // xxxxxoooo
      c = m;
    else
      d = m;
  }
  while (b - a > 1) {
    int m = (a + b) / 2;
    cout << "? " << m + 1 << " " << b << " " << 1 << " " << n << "\n";
    int t;
    cin >> t;
    if (b - m > t)  // xxxxxoooo
      a = m;
    else
      b = m;
  }
  cout << "! " << a + 1 << " " << c + 1 << "\n";
  return 0;
}