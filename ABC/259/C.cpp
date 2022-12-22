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
vector<pair<char, int>> encode(const string& str) {
  int n = (int)str.size();
  vector<pair<char, int>> ret;
  for (int l = 0; l < n;) {
    int r = l + 1;
    while (r < n && str[l] == str[r]) {
      r++;
    }
    ret.push_back({str[l], r - l});
    l = r;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  string s, t;
  cin >> s >> t;

  vector<pair<char, int>> Xs, Xt;
  Xs = encode(s);
  Xt = encode(t);

  int len_Xs = Xs.size();
  int len_Xt = Xt.size();

  if (len_Xs != len_Xt) {
    cout << "No\n";
    return 0;
  }
  for (int i = 0; i < len_Xs; i++) {
    if (Xs[i].first != Xt[i].first || Xs[i].second > Xt[i].second ||
        (Xs[i].second < Xt[i].second && Xs[i].second == 1)) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}