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
  string s;
  cin >> s;
  vector<bool> Retsu(7, false);
  if (s[0] == '1') {
    cout << "No\n";
    return 0;
  }

  if (s[6] == '1') {
    Retsu[0] = true;
  }
  if (s[3] == '1') {
    Retsu[1] = true;
  }
  if (s[1] == '1' || s[7] == '1') {
    Retsu[2] = true;
  }
  if (s[4] == '1') {
    Retsu[3] = true;
  }
  if (s[2] == '1' || s[8] == '1') {
    Retsu[4] = true;
  }
  if (s[5] == '1') {
    Retsu[5] = true;
  }
  if (s[9] == '1') {
    Retsu[6] = true;
  }

  for (int i = 0; i < 5; i++) {
    if (!Retsu[i]) continue;
    for (int j = i + 1; j < 6; j++) {
      if (Retsu[j]) {
        continue;
      }
      for (int k = j + 1; k < 7; k++) {
        if (!Retsu[k]) {
          continue;
        }
        cout << "Yes\n";
        return 0;
      }
    }
  }
  cout << "No\n";

  return 0;
}