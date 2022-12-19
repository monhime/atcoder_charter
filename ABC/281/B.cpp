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
  int len_s = s.size();

  if ((s[0] < 'A') || (s[0] > 'Z')) {
    cout << "No\n";
    return 0;
  }
  if ((s[len_s - 1] < 'A') || (s[len_s - 1] > 'Z')) {
    cout << "No\n";
    return 0;
  }
  if (len_s != 8) {
    cout << "No\n";
    return 0;
  }
  for (int i = 1; i < 7; i++) {
    if ((s[i] < '0') || (s[i] > '9')) {
      cout << "No\n";
      return 0;
    }
  }
  int suzi = stoi(s.substr(1, 6));
  if ((suzi < 100000) || (suzi > 999999)) {
    cout << "No\n";
  } else {
    cout << "Yes\n";
  }

  return 0;
}