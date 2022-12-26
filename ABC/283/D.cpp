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

  stack<char> stack_c;
  set<char> set_c;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == ')') {
      while (stack_c.top() != '(') {
        set_c.erase(stack_c.top());
        stack_c.pop();
      }
      stack_c.pop();
    } else if (s[i] == '(') {
      stack_c.emplace(s[i]);
    } else {
      if (set_c.count(s[i])) {
        cout << "No\n";
        return 0;
      }
      stack_c.emplace(s[i]);
      set_c.emplace(s[i]);
    }
  }
  cout << "Yes\n";

  return 0;
}