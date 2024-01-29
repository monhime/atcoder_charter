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

  int n;
  cin >> n;
  vvi A(n, vi(n, 0)), B(n, vi(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> B[i][j];
    }
  }

  // 0度
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[i][j] && !B[i][j]) {
        goto A;
      }
    }
  }
  cout << "Yes\n";
  return 0;
A:
  // 90度
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[n - j - 1][i] && !B[i][j]) {
        goto B;
      }
    }
  }
  cout << "Yes\n";
  return 0;
B:

  // 270度
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[j][n - 1 - i] && !B[i][j]) {
        goto C;
      }
    }
  }
  cout << "Yes\n";
  return 0;
C:

  // 360度
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (A[n - i - 1][n - 1 - j] && !B[i][j]) {
        goto D;
      }
    }
  }
  cout << "Yes\n";
  return 0;
D:
  cout << "No\n";

  return 0;
}