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

  int n, c, a;
  cin >> n;
  vvi A(37, vi(n, 0));  // 数字iは、、人jに選ばれたとき、その人の賭け数

  for (int i = 0; i < n; i++) {
    cin >> c;
    for (int j = 0; j < c; j++) {
      cin >> a;
      A[a][i] = c;
    }
  }

  int x;
  cin >> x;

  vector<Pii> pair_c_i;  // 数字xを当てた人の賭け数と、人の番号
  for (int i = 0; i < n; i++) {
    if (A[x][i]) {
      pair_c_i.emplace_back(A[x][i], i);
    }
  }

  sort(ALL(pair_c_i));

  if (!pair_c_i.size()) {
    cout << "0\n\n";
    return 0;
  }
  int ans = 0;
  for (auto& p : pair_c_i) {
    if (p.first == pair_c_i[0].first) {
      ans++;
    }
  }
  cout << ans << "\n";

  for (int i = 0; i < ans; i++) {
    cout << pair_c_i[i].second + 1 << " ";
  }
  cout << "\n";

  return 0;
}