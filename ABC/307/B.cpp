#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(), (x).end()
#define debug(x) std::cerr << #x << ": " << x << '\n'

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;

template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int n;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; i++) {
    cin >> S[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }

      int s_i_size = S[i].size(), s_j_size = S[j].size();
      bool not_kaibun = false;

      if (s_i_size <= s_j_size) {
        for (int k = 0; k < s_i_size; k++) {
          if (S[i][k] != S[j][s_j_size - k - 1]) {
            not_kaibun = true;
            break;
          }
        }
        if (not_kaibun) {
          continue;
        }

        for (int k = s_i_size; k < (s_i_size + s_j_size) / 2; k++) {
          if (S[j][k - s_i_size] != S[j][s_j_size - k - 1]) {
            not_kaibun = true;
            break;
          }
        }
        if (!not_kaibun) {
          cout << "Yes\n";
          return 0;
        }
      }

      if (s_i_size > s_j_size) {
        for (int k = 0; k < s_j_size; k++) {
          if (S[i][k] != S[j][s_j_size - k - 1]) {
            not_kaibun = true;
            break;
          }
        }
        if (not_kaibun) {
          continue;
        }

        for (int k = s_j_size; k < (s_i_size + s_j_size) / 2; k++) {
          if (S[i][k] != S[i][s_i_size - k + s_j_size - 1]) {
            not_kaibun = true;
            break;
          }
        }
        if (!not_kaibun) {
          cout << "Yes\n";
          return 0;
        }
      }
    }
  }
  cout << "No\n";

  return 0;
}