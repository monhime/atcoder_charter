#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1},
              dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

  int n;
  cin >> n;
  vector<string> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  vector<string> A_mat(3 * n);
  for (int i = 0; i < 3 * n; i++) {
    A_mat[i] = A[i % n] + A[i % n] + A[i % n];
  }

  ll ans = 0ll;
  for (int i = 0; i < n; i++) {
    int start_y = n + i;
    for (int j = 0; j < n; j++) {
      int start_x = n + j;
      for (int direc = 0; direc < 8; direc++) {
        int _dx = dx[direc];
        int _dy = dy[direc];

        string suji = "";
        for (int k = 0; k < n; k++) {
          suji += A_mat[start_y + _dy * k][start_x + _dx * k];
        }
        ans = max(ans, stoll(suji));
      }
    }
  }
  cout << ans << "\n";

  return 0;
}