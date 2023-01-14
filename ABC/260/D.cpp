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

  int n, k, p;
  cin >> n >> k;
  vi Ans(n, -1);          // 各番号 - 1がいつ消えるか
  map<int, vi> map_yama;  // 各山の番号と，その中身
  map<int, int> map_last;  // 各山の一番上のカードと，その山の番号

  for (int i = 0; i < n; i++) {
    cin >> p;
    auto iter = map_last.lower_bound(p);
    int yama_number;

    if (iter == map_last.end()) {
      // 新しい山
      if (map_last.size()) {
        iter--;
        yama_number = iter->first + 1;
      } else {
        yama_number = 1;
      }
      map_yama[yama_number].emplace_back(p);

      map_last[p] = yama_number;
    } else {
      // すでにある山
      yama_number = iter->second;  // 山番号
      map_yama[yama_number].emplace_back(p);

      // map_lastの更新
      map_last[p] = yama_number;
      map_last.erase(iter);
    }
    // debug(yama_number);
    // for (int i = 0; i < map_yama[yama_number].size(); i++) {
    //   cout << map_yama[yama_number][i] << " ";
    // }
    // cout << "\n";
    if (map_yama[yama_number].size() == k) {
      for (auto& x : map_yama[yama_number]) {
        Ans[x - 1] = i + 1;
      }
      map_yama.erase(yama_number);
      map_last.erase(p);
    }
  }
  for (int i = 0; i < n; i++) {
    cout << Ans[i] << " ";
  }
  cout << "\n";

  return 0;
}