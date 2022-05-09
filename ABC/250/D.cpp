#include <iostream>
#include <vector>
using ll = long long;
#define MAXP 1000005

void eratosthenes_sieve(std::vector<ll> &prime_list) {
  // エラトステネスの篩でMAXP未満の素数を求める O(nloglogn) 1e6までok
  std::vector<bool> Sieve(MAXP, false);
  for (int i = 2; i < MAXP; i++) {
    if (Sieve[i]) {
      continue;
    }
    prime_list.emplace_back(i);
    for (int j = i; j < MAXP; j += i) {
      Sieve[j] = true;
    }
  }
}

ll f(ll p, ll q) {
  double est = p * q * q * q;  // 64 bitを超える場合があるためdouble
  return (est > 4e18 ? 4e18 : est);
}

int main() {
  std::vector<ll> prime_list;
  eratosthenes_sieve(prime_list);

  ll n;
  std::cin >> n;

  ll res = 0;
  int prime_list_size = prime_list.size();
  int q = prime_list_size - 1;
  for (int p = 0; p < prime_list_size; p++) {
    while (p < q && f(prime_list[p], prime_list[q]) > n) {
      // p < q < (n/p)^1/3 になるまでqを減らす
      q--;
    }
    if (p >= q) {
      break;
    }
    res += (q - p);
  }
  std::cout << res << "\n";
  return 0;
}
