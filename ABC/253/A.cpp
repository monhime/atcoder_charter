#include <iostream>
#define debug(x) std::cerr << #x << ": " << x << '\n'

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int a, b, c;
    std::cin >> a >> b >> c;

    if ((a <= b && b <= c) || (a >= b && b >= c)){
        std::cout << "Yes\n";
    }
    else
    {
        std::cout << "No\n";
    }

    return 0;
}
