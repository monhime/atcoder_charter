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
  if (s == "atcoder") {
    cout << "0\n";
    return 0;
  }

  queue<string> Q;
  Q.emplace("atcoder");
  set<string> S_set;
  map<string, int> map_sedai;
  S_set.emplace("atcoder");
  map_sedai["atcoder"] = 0;

  while (!Q.empty()) {
    string node = Q.front();
    Q.pop();
    for (int i = 0; i < s.size() - 1; i++) {
      string new_node = node;
      swap(new_node[i], new_node[i + 1]);
      if (S_set.count(new_node)) {
        continue;
      }
      S_set.emplace(new_node);
      if (new_node == s) {
        cout << map_sedai[node] + 1 << "\n";
        return 0;
      }
      map_sedai[new_node] = map_sedai[node] + 1;
      Q.emplace(new_node);
    }
  }

  return 0;
}