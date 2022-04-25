#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> AB(m);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    AB[i] = make_pair(a, b);
  }
  sort(AB.begin(), AB.end());
  vector<pair<int, int>> CD(m), CD_tmp(m);
  for (int i = 0; i < m; i++) {
    int c, d;
    cin >> c >> d;
    CD_tmp[i] = make_pair(c, d);
  }
  CD = CD_tmp;
  vector<int> taio(10);
  for (int i = 1; i < 9; i++) {
    taio[i] = i;
  }
  do {
    for (int i = 0; i < m; i++) {
      int c = taio[CD_tmp[i].first];
      int d = taio[CD_tmp[i].second];
      CD[i].first = min(c, d);
      CD[i].second = max(c, d);
    }
    sort(CD.begin(), CD.end());
    bool flag = true;
    for (int i = 0; i < m; i++) {
      if (AB[i].first != CD[i].first || AB[i].second != CD[i].second) {
        flag = false;
      }
    }
    if (flag) {
      cout << "Yes\n";
      return 0;
    }
  } while (next_permutation(taio.begin(), taio.end()));
  cout << "No\n";

  return 0;
}
