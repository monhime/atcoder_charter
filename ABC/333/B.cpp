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

  string s, t;
  cin >> s >> t;

  // 昇順
  if (s[0] > s[1]) {
    reverse(ALL(s));
  }
  if (t[0] > t[1]) {
    reverse(ALL(t));
  }
  //   debug(s);
  //   debug(t);

  // Aを始点
  int delta_s = s[0] - 'A';
  s[1] -= delta_s;
  s[0] -= delta_s;

  int delta_t = t[0] - 'A';
  t[1] -= delta_t;
  t[0] -= delta_t;

  //   debug(s);
  //   debug(t);

  if (s[1] == 'D') {
    s[1] = 'C';
  }
  if (s[1] == 'E') {
    s[1] = 'B';
  }
  if (t[1] == 'D') {
    t[1] = 'C';
  }
  if (t[1] == 'E') {
    t[1] = 'B';
  }

  if (s[1] == t[1]) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}