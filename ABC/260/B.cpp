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
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  vi A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  vvi ABC(n, vi(4));
  for (int i = 0; i < n; i++) {
    ABC[i][0] = i;
    ABC[i][1] = A[i];
    ABC[i][2] = B[i];
    ABC[i][3] = A[i] + B[i];
  }
  set<int> Gokaku;
  sort(ALL(ABC), [](const vector<int>& alpha, const vector<int>& beta) {
    if (alpha[1] > beta[1])
      return true;
    else if (alpha[1] == beta[1])
      return alpha[0] < beta[0];
    return false;
  });
  for (int i = 0; i < x; i++) {
    Gokaku.emplace(ABC[i][0]);
  }

  sort(ALL(ABC), [](const vector<int>& alpha, const vector<int>& beta) {
    if (alpha[2] > beta[2])
      return true;
    else if (alpha[2] == beta[2])
      return alpha[0] < beta[0];
    return false;
  });
  int cunt_eigo = 0;
  int i = 0;
  while (cunt_eigo < y) {
    if (!Gokaku.count(ABC[i][0])) {
      Gokaku.emplace(ABC[i][0]);
      cunt_eigo++;
    }
    i++;
  }

  sort(ALL(ABC), [](const vector<int>& alpha, const vector<int>& beta) {
    if (alpha[3] > beta[3])
      return true;
    else if (alpha[3] == beta[3])
      return alpha[0] < beta[0];
    return false;
  });
  int cunt_suei = 0;
  i = 0;
  while (cunt_suei < z) {
    if (!Gokaku.count(ABC[i][0])) {
      Gokaku.emplace(ABC[i][0]);
      cunt_suei++;
    }
    i++;
  }

  for (auto gokaku : Gokaku) {
    cout << gokaku + 1 << "\n";
  }

  return 0;
}
