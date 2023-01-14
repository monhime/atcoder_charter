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

  int h, w, n;
  cin >> h >> w;
  int cur_r, cur_c;
  cin >> cur_r >> cur_c;
  cur_r--;
  cur_c--;
  cin >> n;

  map<int, set<int>> map_r_c, map_c_r;

  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    r--;
    c--;
    map_r_c[r].emplace(c);
    map_c_r[c].emplace(r);
  }

  int q;
  cin >> q;
  for (int qq = 0; qq < q; qq++) {
    char d;
    int l;
    cin >> d >> l;
    if (d == 'R') {
      auto itr = map_r_c[cur_r].upper_bound(cur_c);
      if (itr == map_r_c[cur_r].end()) {
        cur_c = min(cur_c + l, w - 1);
      } else {
        cur_c = min(cur_c + l, *itr - 1);
      }
    } else if (d == 'L') {
      auto itr = map_r_c[cur_r].upper_bound(cur_c);
      if (itr == map_r_c[cur_r].begin()) {
        cur_c = max(cur_c - l, 0);
      } else {
        itr--;
        cur_c = max(cur_c - l, *itr + 1);
      }
    } else if (d == 'U') {
      auto itr = map_c_r[cur_c].upper_bound(cur_r);
      if (itr == map_c_r[cur_c].begin()) {
        cur_r = max(cur_r - l, 0);
      } else {
        itr--;
        cur_r = max(cur_r - l, *itr + 1);
      }
    } else if (d == 'D') {
      auto itr = map_c_r[cur_c].upper_bound(cur_r);
      if (itr == map_c_r[cur_c].end()) {
        cur_r = min(cur_r + l, h - 1);
      } else {
        cur_r = min(cur_r + l, *itr - 1);
      }
    }
    cout << cur_r + 1 << " " << cur_c + 1 << "\n";
  }

  return 0;
}