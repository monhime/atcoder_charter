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

  int h1, w1;
  cin >> h1 >> w1;
  vvi A(h1, vi(w1));
  for (int i = 0; i < h1; i++) {
    for (int j = 0; j < w1; j++) {
      cin >> A[i][j];
    }
  }
  int h2, w2;
  cin >> h2 >> w2;
  vvi B(h2, vi(w2));
  for (int i = 0; i < h2; i++) {
    for (int j = 0; j < w2; j++) {
      cin >> B[i][j];
    }
  }

  vi erase_row(h1, 0), erase_col(w1, 0);
  for (int i = h2; i < h1; i++) {
    erase_row[i] = 1;
  }
  for (int i = w2; i < w1; i++) {
    erase_col[i] = 1;
  }

  do {
    do {
      int idx_h2 = 0;
      bool ok_flag = true;

      for (int idx_h1 = 0; idx_h1 < h1; idx_h1++) {
        if (erase_row[idx_h1]) {
          continue;
        }
        int idx_w2 = 0;
        for (int idx_w1 = 0; idx_w1 < w1; idx_w1++) {
          if (erase_col[idx_w1]) {
            continue;
          }
          if (A[idx_h1][idx_w1] != B[idx_h2][idx_w2]) {
            ok_flag = false;

            break;
          }

          idx_w2++;
        }
        if (!ok_flag) {
          break;
        }

        idx_h2++;
      }
      if (ok_flag) {
        cout << "Yes\n";
        return 0;
      }

    } while (next_permutation(ALL(erase_col)));

  } while (next_permutation(ALL(erase_row)));
  cout << "No\n";

  return 0;
}