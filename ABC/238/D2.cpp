#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  ll a, s;
  vector<ll> A(t), S(t);
  for (int i = 0; i < t; i++) {
    cin >> A[i] >> S[i];
  }
  for (int i = 0; i < t; i++) {
    ll a = A[i];
    ll s = S[i];
    // aで1の位はxもyも1
    // 0の位はどちらか一方だけが1、または両方0
    // どちらか一方が1のとき、それがxでもyでも変わらない→xとする
    // s から a*2を引く→ それが a とビット論理積で完全に0ならok
    // a = 1, s = 8:
    // 1000→110 & 001 =
    if (s - a * 2ll >= 0ll && (s - a * 2ll & a) == 0ll) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }

  return 0;
}
