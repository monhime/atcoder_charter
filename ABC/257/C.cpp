#include <bits/stdc++.h>
using namespace std;
#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
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
using vvi = vector<vector<int>>;
using vll = vector<ll>;

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
  string s;
  cin >> n >> s;
  vi Otona, Kodomo, W(n);

  for (int i = 0; i < n; i++) {
    cin >> W[i];
    if (s[i] == '1') {
      Otona.emplace_back(W[i]);
    } else {
      Kodomo.emplace_back(W[i]);
    }
  }
  if (Otona.size() * Kodomo.size() == 0) {
    cout << n << "\n";
    return 0;
  }

  sort(ALL(Otona));
  sort(ALL(Kodomo));
  //   for (int i = 0; i < Otona.size(); i++) {
  //     cout << Otona[i] << " ";
  //   }
  //   cout << "\n";
  //   for (int i = 0; i < Kodomo.size(); i++) {
  //     cout << Kodomo[i] << " ";
  //   }
  //   cout << "\n";

  int ans = 0;
  for (int i = 0; i < Otona.size(); i++) {
    int miss_kodomo =
        distance(lower_bound(ALL(Kodomo), Otona[i]), Kodomo.end());
    int miss_otona =
        distance(Otona.begin(), upper_bound(ALL(Otona), Otona[i] - 1));
    ans = max(ans, n - miss_kodomo - miss_otona);
    // cout << Otona[i] << " " << miss_kodomo << " " << miss_otona << " " << ans
    //      << "\n";
  }
  cout << ans << "\n";

  return 0;
}