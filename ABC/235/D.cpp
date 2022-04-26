#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, n;
  cin >> a >> n;

  priority_queue<pair<int, int>> pQ;
  set<int> set_a;
  set_a.emplace(1);
  pQ.emplace(make_pair(0, 1));  //回数、数字

  int keta_n = to_string(n).length();
  while (!pQ.empty()) {
    int kaisu, node;
    tie(kaisu, node) = pQ.top();
    kaisu *= -1;
    // debug(kaisu);
    // debug(node);
    pQ.pop();
    if (node == n) {
      cout << kaisu << "\n";
      return 0;
    }
    int xnode = node * a;
    int xkaisu = kaisu + 1;
    while (xnode < pow(10, 6) && !set_a.count(xnode)) {
      set_a.emplace(xnode);
      pQ.emplace(make_pair(-xkaisu++, xnode));
      xnode *= a;
    }

    int keta_node = to_string(node).length();
    if (keta_node >= 2 && node % 10 && keta_node <= keta_n) {
      xnode = node;
      xkaisu = kaisu;
      for (;;) {
        string node_s = to_string(xnode);
        xnode = stoi(node_s.back() + node_s.substr(0, keta_node - 1));
        if (xnode % 10 && !set_a.count(xnode)) {
          set_a.emplace(xnode);
          pQ.emplace(make_pair(-++xkaisu, xnode));
        } else {
          break;
        }
      }
    }
  }
  cout << "-1\n";

  return 0;
}
