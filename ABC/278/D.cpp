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

  int n;
  cin >> n;
  vll A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int q;
  cin >> q;
  ll all_plus = 0ll;
  set<int> Kousin;  // 変更済み
  ll kousin_x = -1ll;

  for (int qq = 0; qq < q; qq++) {
    int query, i_q;
    ll x_q;

    cin >> query;

    if (query == 1) {
      cin >> kousin_x;
      Kousin = {};
    } else if (query == 2) {
      cin >> i_q >> x_q;
      i_q--;
      if (kousin_x == -1 || Kousin.count(i_q)) {
        A[i_q] += x_q;
      } else {
        A[i_q] = kousin_x + x_q;
        Kousin.emplace(i_q);
      }
    } else {
      cin >> i_q;
      i_q--;
      if (kousin_x != -1 && !Kousin.count(i_q)) {
        A[i_q] = kousin_x;
        Kousin.emplace(i_q);
      }
      cout << A[i_q] << "\n";
    }
  }

  return 0;
}