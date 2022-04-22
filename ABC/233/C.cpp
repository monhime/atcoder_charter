#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

void dfs(int pos, ll seki, int &ans, const int &n, const ll &x,
         const vector<int> &L, const vector<vector<ll>> &A) {
  if (pos == n) {
    if (seki == x) {
      ans++;
    }
    return;
  }
  for (int i = 0; i < L[pos]; i++) {
    ll n_a = A[pos][i];
    if (seki * n_a > x) {
      continue;
    }
    dfs(pos + 1, seki * n_a, ans, n, x, L, A);
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, a;
  ll x;
  cin >> n >> x;
  // 選び方の総数は10^5以下→全探索可能
  vector<int> L(n);
  vector<vector<ll>> A(n);
  for (int i = 0; i < n; i++) {
    cin >> L[i];
    for (int j = 0; j < L[i]; j++) {
      cin >> a;
      A[i].emplace_back(a);
    }
  }
  int ans = 0;
  dfs(0, 1ll, ans, n, x, L, A);
  cout << ans << "\n";

  return 0;
}
