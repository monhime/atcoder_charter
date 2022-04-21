#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int ans = 0;
  int a;
  stack<pair<int, int>> Stack;
  cin >> a;
  Stack.emplace(make_pair(a, 1));
  cout << 1 << "\n";
  ans = 1;
  for (int i = 1; i < n; i++) {
    cin >> a;
    int p_a, p_cunt;
    if (!Stack.size()) {
      Stack.emplace(make_pair(a, 1));
      ans++;
      cout << ans << "\n";
      continue;
    }
    tie(p_a, p_cunt) = Stack.top();
    if (a != p_a) {
      Stack.emplace(make_pair(a, 1));
      ans++;
    } else {
      if (p_cunt + 1 == a) {
        Stack.pop();
        ans -= p_cunt;
      } else {
        Stack.pop();
        Stack.emplace(make_pair(a, p_cunt + 1));
        ans++;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
