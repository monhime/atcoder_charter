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

  vector<int> T_front(n, -1), T_back(n, -1);
  vi A;
  for (int qq = 0; qq < q; qq++) {
    int flag, x, y;
    cin >> flag;

    if (flag == 1) {
      cin >> x >> y;
      T_back[x - 1] = y - 1;
      T_front[y - 1] = x - 1;
    } else if (flag == 2) {
      cin >> x >> y;
      T_back[x - 1] = -1;
      T_front[y - 1] = -1;
    } else {
      cin >> x;
      x--;

      while (T_front[x] != -1) {
        x = T_front[x];
      }

      A = {};
      do {
        A.emplace_back(x + 1);
        x = T_back[x];
      } while (x != -1);

      cout << A.size() << " ";

      for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}