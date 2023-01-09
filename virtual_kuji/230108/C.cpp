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

  int n;
  ll k;
  cin >> n >> k;
  vi A(n);
  vector<int> visited(n, -1);  // 何回テレポートした後にくるか
  vector<int> route;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> a;
    A[i] = a - 1;
  }
  if (A[0] == 1) {
    cout << 1 << "\n";
    return 0;
  }

  int node = 0;
  int cunt = 0;
  while (visited[node] == -1) {
    visited[node] = cunt;
    int xnode = A[node];
    route.emplace_back(node);
    cunt++;
    node = xnode;
    // cout << node << "\n";
  }
  k -= (ll)visited[node];
  k %= (ll)(cunt - visited[node]);
  k += (ll)visited[node];
  cout << node << " " << visited[node] << " " << cunt << " " << k << "\n";

  //   for (int i = 0; i < route.size(); i++) {
  //     cout << route[i] << " ";
  //   }
  //   cout << "\n";
  //   for (int i = 0; i < n; i++) {
  //     cout << visited[i] << " ";
  //   }
  //   cout << "\n";

  //   cout << cunt << "\n";

  cout << route[k] + 1 << "\n";

  return 0;
}