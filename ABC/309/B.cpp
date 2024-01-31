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
  vector<string> A(n);

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  cout << A[1][0] << A[0].substr(0, n - 1) << "\n";

  for (int i = 1; i < n - 1; i++) {
    cout << A[i + 1][0] << A[i].substr(1, n - 2) << A[i - 1][n - 1] << "\n";
  }

  cout << A[n - 1].substr(1, n - 1) << A[n - 2][n - 1] << "\n";

  return 0;
}