#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<pair<int, int>> pq_AB;
  int a, b;

  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    pq_AB.emplace(make_pair(-a, 1));
    pq_AB.emplace(make_pair(-(a + b), -1));
  }
  vector<int> K(n);
  int cunt = 0;
  int cunt_pre = 0;
  int ans = 0;
  int cur_idx;
  tie(cur_idx, ignore) = pq_AB.top();
  cur_idx *= -1;
  int last_idx = cur_idx;
  while (pq_AB.size()) {
    int pm, idx;
    tie(idx, pm) = pq_AB.top();
    idx *= -1;
    if (idx == cur_idx) {
      cunt += pm;
      pq_AB.pop();
    }
    if (idx != cur_idx || !pq_AB.size()) {
      if (cunt_pre > 0) {
        K[cunt_pre - 1] += cur_idx - last_idx;
      }
      last_idx = cur_idx;
      cur_idx = idx;
      cunt_pre = cunt;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << K[i] << " ";
  }
  cout << "\n";

  return 0;
}
