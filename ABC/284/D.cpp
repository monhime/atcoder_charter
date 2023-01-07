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

int MAXP = 3000000;
void eratosthenes_sieve(std::set<ll>& prime_list) {
  // エラトステネスの篩でMAXP未満の素数を求める O(nloglogn) 1e6までok
  std::vector<bool> Sieve(MAXP, false);
  for (int i = 2; i < MAXP; i++) {
    if (Sieve[i]) {
      continue;
    }
    prime_list.emplace((ll)i);
    for (int j = i; j < MAXP; j += i) {
      Sieve[j] = true;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);  // std::cinとscanf()を混ぜない
  cin.tie(nullptr);             // インタラクティブ実行不可

  int t;
  cin >> t;
  set<ll> prime_list;
  eratosthenes_sieve(prime_list);
  for (int i = 0; i < t; i++) {
    ll n;
    cin >> n;
    bool flag = false;
    for (ll p = 2; p < (ll)MAXP; p++) {
      if (n % (p * p) == 0ll && prime_list.count(p)) {
        ll q = n / (p * p);
        cout << p << " " << q << "\n";
        flag = true;
        break;
      }
    }
    if (!flag) {
      for (ll q = 2; q < (ll)MAXP; q++) {
        if (n % q == 0ll && prime_list.count(q)) {
          ll p_tmp = (ll)sqrt(n / q);
          for (int i = -100; i < 100; i++) {
            ll p = p_tmp + i;
            if (p * p * q == n) {
              cout << p << " " << q << "\n";
              break;
            }
          }
        }
      }
    }
  }

  return 0;
}