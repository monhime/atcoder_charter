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

  int n, q;
  cin >> n >> q;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(ALL(A));

  vll S(n + 1, 0);
  for (int i = 0; i < n; i++) {
    S[i + 1] = S[i] + A[i];
  }
  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;

    // 最終的にA[left] < x <= A[right]
    int left = 0;
    int right = n - 1;
    while (left <= right) {
      int mid = (left + right) / 2;
      if (A[mid] < x) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    swap(left, right);
    // cout << left << " " << right << "\n";
    ll res = x * (left + 1) - S[left + 1];
    res += (S[n] - S[right]) - x * (n - right);
    cout << res << '\n';
  }
  return 0;
}