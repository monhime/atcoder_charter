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

  map<int, int> map_A;
  vi Sedai(2 * n + 2, -1);
  Sedai[1] = 0;
  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    map_A[2 * i] = a;
    map_A[2 * i + 1] = a;
    Sedai[2 * i] = Sedai[a] + 1;
    Sedai[2 * i + 1] = Sedai[a] + 1;
  }
  for (int i = 1; i <= 2 * n + 1; i++) {
    cout << Sedai[i] << "\n";
  }

  return 0;
}