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
  int n;
  cin >> n;
  vi A(n), Ans(n, 0);
  set<int> A_set;
  map<int, int> A_map;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    A_set.emplace(A[i]);
  }
  int cunt = 0;  // 大きい数字の種類
  while (A_set.size()) {
    int a = *A_set.rbegin();
    A_set.erase(a);
    if (!A_map[a]) {
      A_map[a] = cunt;
      cunt++;
    }
  }

  for (int i = 0; i < n; i++) {
    Ans[A_map[A[i]]]++;  // A[i]より大きい数字の種類の数について+1
  }
  for (int i = 0; i < n; i++) {
    cout << Ans[i] << "\n";
  }

  return 0;
}