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

  int n;
  cin >> n;

  vector<bool> vol_flag(n + 2, false);  // 持ってるかどうか
  vi A(n);

  int sold = 0;  // 売る数
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (A[i] >= vol_flag.size())
      sold++;
    else if (vol_flag[A[i]])
      sold++;
    else
      vol_flag[A[i]] = true;
  }

  int left = 1;
  int right = n + 1;  // 売る候補
  while (true) {
    while (vol_flag[left]) {
      // 　読めなくなるまで
      left++;
    }
    while (right != 0 && !vol_flag[right]) {
      // 持ってる巻を探す
      right--;
    }
    if (sold >= 2) {
      // 売れる本2冊以上あるなら
      sold -= 2;
      vol_flag[left] = true;
    } else {
      // 売れる本2冊以上ないなら
      if (left >= right) {
        // 売れる本が無い
        break;
      }
      vol_flag[right] = false;  // 本を売る
      sold++;                   // 売るストック増やす
    }
  }

  cout << left - 1 << endl;

  return 0;
}