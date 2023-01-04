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

  int n, m;
  cin >> n >> m;

  vll A(n), A2(2 * n);
  ll sum_A = 0ll;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum_A += A[i];
  }
  sort(ALL(A));

  for (int i = 0; i < n; i++) {
    A2[i] = A[i];
  }
  for (int i = 0; i < n; i++) {
    A2[n + i] = m + A[i];
  }

  //   for (int i = 0; i < 2 * n; i++) {
  //     cout << A2[i] << " ";
  //   }
  //   cout << "\n";

  int left = 0;
  int right = 0;

  ll ans = llinf;
  while (left < n) {
    right++;
    ll tmp;
    if (left >= n) {
      tmp = A2[left - n];
    } else {
      tmp = A2[left];
    }

    while (right <= left + n) {
      if (A2[right] == A2[right - 1] || A2[right] == A2[right - 1] + 1ll) {
        right++;
        if (right - 1 >= n) {
          tmp += A2[right - 1 - n];
        } else {
          tmp += A2[right - 1];
        }
      } else {
        // 同じか連続して増えない
        break;
      }
    }
    // cout << left << " " << right << " " << tmp << "\n";
    chmin(ans, sum_A - tmp);
    left = right;
  }
  cout << ans << "\n";

  return 0;
}