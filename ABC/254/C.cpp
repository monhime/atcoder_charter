#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
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
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n, k;
  cin >> n >> k;
  vi A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  if (k == 1) {
    cout << "Yes\n";
    return 0;
  }

  // mod Kが同じ位置の中でsort（K*(n/K log (n/k)=nlog(n/k)）
  // ↑の結果、全体が昇順になるか？
  vvi A_mod(k);
  for (int i = 0; i < n; i++) {
    A_mod[i % k].emplace_back(A[i]);
  }
  for (int i = 0; i < k; i++) {
    sort(ALL(A_mod[i]));
    // for (int j = 0; j < A_mod[i].size(); j++) {
    //   cout << A_mod[i][j] << " ";
    // }
    // cout << "\n";
  }
  int pre = 0;
  for (int i = 0; i < n; i++) {
    int a_mod = A_mod[i % k][i / k];
    // cout << a_mod << "\n";
    if (a_mod < pre) {
      cout << "No\n";
      return 0;
    }
    pre = a_mod;
  }
  cout << "Yes\n";

  return 0;
}