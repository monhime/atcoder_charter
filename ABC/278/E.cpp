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
  cin.tie(nullptr);             // インタラクティブ実行不可

  int H, W, n, h, w;
  cin >> H >> W >> n >> h >> w;
  vvi A(H, vi(W));
  set<int> setA, subsetA;

  for (int hh = 0; hh < H; hh++) {
    for (int ww = 0; ww < W; ww++) {
      cin >> A[hh][ww];
      setA.emplace(A[hh][ww]);
    }
  }

  for (int k = 0; k <= H - h; k++) {
    // 左端だけ毎回カウント
    for (int i = k; i < k + h; i++) {
      for (int j = 0; j < w; j++) {
        subsetA.emplace(A[i][j]);
      }
    }
    for (int l = 0; l < W - w; l++) {
      int old_col = l;
      int new_col = l + w;
      for (int i = k; i < k + h; i++) {
            }
    }
  }

  return 0;
}