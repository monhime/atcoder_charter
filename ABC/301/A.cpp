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

  int n;
  string s;
  cin >> n >> s;
  int cunt_t = 0, cunt_a = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      cunt_a++;
    } else {
      cunt_t++;
    }
  }
  if (cunt_a < cunt_t) {
    cout << "T\n";
  } else if (cunt_a > cunt_t) {
    cout << "A\n";
  } else {
    if (s[n - 1] == 'T') {
      cout << "A\n";
    } else {
      cout << "T\n";
    }
  }

  return 0;
}