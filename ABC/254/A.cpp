#include <iostream>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    std::string n;
    std::cin >> n;

    std::cout << n.substr(1, 2) << "\n";

    return 0;
}
