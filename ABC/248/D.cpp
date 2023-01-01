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
  int a;
  vvi Apos(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a;
    Apos[a].emplace_back(i);
  }
  //   for (int i = 0; i <= n; i++) {
  //     sort(ALL(Apos[i]));
  //     cout << i << " ";
  //     for (int j = 0; j < Apos[i].size(); j++) {
  //       cout << Apos[i][j] << " ";
  //     }
  //     cout << "\n";
  //   }

  int q;
  cin >> q;
  for (int qq = 0; qq < q; qq++) {
    int l, r, x;
    cin >> l >> r >> x;
    l--;
    r--;

    int l_idx = distance(Apos[x].begin(), lower_bound(ALL(Apos[x]), l));
    int r_idx = distance(Apos[x].begin(), upper_bound(ALL(Apos[x]), r));
    // cout << l_idx << " " << r_idx << "\n";
    cout << r_idx - l_idx << "\n";
  }

  return 0;
}