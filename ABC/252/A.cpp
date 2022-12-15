#include <iostream>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::cout << char('a' + (n - 97)) << "\n";

    return 0;
}
