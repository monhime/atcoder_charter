#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  bool flag_big = false;
  bool flag_small = false;
  map<char, int> map_S;
  for (auto &c : s) {
    if (c >= 'a' && c <= 'z') {
      flag_small = true;
    } else if (c >= 'A' && c <= 'Z') {
      flag_big = true;
    }
    if (map_S[c]) {
      cout << "No\n";
      return 0;
    }
    map_S[c]++;
  }
  if (flag_big && flag_small) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
