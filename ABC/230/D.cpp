#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, d;
  cin >> n >> d;
  vector<pair<int, int>> RL(n);
  for (int i = 0; i < n; i++) {
    cin >> RL[i].second >> RL[i].first;
  }
  // 右端でソート→破壊されてない壁の中でもっとも左にある壁を含むように
  sort(RL.begin(), RL.end());
  int hakai_r = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (hakai_r < RL[i].second) {  //破壊されてない
      ans++;
      hakai_r = RL[i].first + d - 1;
    }
  }
  cout << ans << "\n";

  return 0;
}
