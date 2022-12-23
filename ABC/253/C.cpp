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

  set<int> set_S;
  map<int, int> map_S;

  int q;
  cin >> q;

  for (int qq = 0; qq < q; qq++) {
    int n, x, c;
    cin >> n;
    if (n == 1) {
      cin >> x;
      set_S.emplace(x);
      map_S[x]++;
    } else if (n == 2) {
      cin >> x >> c;
      if (set_S.count(x)) {
        if (map_S[x] > c) {
          map_S[x] -= c;
        } else {
          map_S[x] = 0;
          set_S.erase(x);
        }
      }
    } else if (n == 3) {
      cout << *set_S.rbegin() - *set_S.begin() << "\n";
    }
  }

  return 0;
}