#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<int> A(n + 1);
  vector<int> C(n + m + 1);
  for (int i = 0; i < n + 1; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n + m + 1; i++) {
    cin >> C[i];
  }
  vector<int> B(m + 1);
  for (int i = m; i >= 0; i--) {
    int b_i = C[n + i] / A[n];
    B[i] = b_i;
    for (int j = 0; j <= n; j++) {
      C[n + i - j] -= b_i * A[n - j];
    }
  }
  for (int i = 0; i <= m; i++) {
    cout << B[i] << " ";
  }
  cout << "\n";

  return 0;
}
