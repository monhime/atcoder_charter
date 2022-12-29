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

  string s;
  cin >> s;

  deque<char> dQ;
  bool right_flag = true;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'R') {
      right_flag ^= true;
      continue;
    }
    if (dQ.empty()) {
      dQ.emplace_back(s[i]);
      continue;
    }

    if (right_flag) {
      char back_c = dQ.back();
      if (back_c == s[i]) {
        dQ.pop_back();
      } else {
        dQ.emplace_back(s[i]);
      }

    } else {
      char front_c = dQ.front();
      if (front_c == s[i]) {
        dQ.pop_front();
      } else {
        dQ.emplace_front(s[i]);
      }
    }
  }
  while (!dQ.empty()) {
    if (!right_flag) {
      cout << dQ.back();
      dQ.pop_back();
    } else {
      cout << dQ.front();
      dQ.pop_front();
    }
  }
  cout << "\n";

  return 0;
}