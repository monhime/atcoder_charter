#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << #x << ": " << x << '\n'
using ll = long long;
constexpr int MOD = 998244353;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }

  vector<int> dp_sum(3001, 1);
  for (int i = 0; i < n; i++) {
    vector<int> dp_tmp(3001, 0);
    int a = A[i];
    int b = B[i];
    for (int j = a; j < b + 1; j++) {
      dp_tmp[j] = dp_sum[j];
    }
    dp_sum[0] = dp_tmp[0];
    for (int j = 1; j < 3001; j++) {
      dp_sum[j] = (dp_sum[j - 1] + dp_tmp[j]) % MOD;
    }
  }
  cout << dp_sum.back() << "\n";

  return 0;
}
