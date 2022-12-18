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
using vvll = vector<vector<ll>>;
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
    int n;
    cin >> n;

    vvll C(2, vll(30, 0ll));//llなら0ll
    C[0][0] = 1ll;
    C[1][0] = 1ll;

    for (int i = 0; i < n; i++) {
        int now = i % 2;
        int pre = (i - 1) % 2;
        C[now][i] = 1;
        cout << "1 ";
        for (int j = 1; j < i; j++) {
          C[now][j] = C[pre][j - 1] + C[pre][j];
          cout << C[now][j] << " ";
        }
        if (i > 0)
        {
            cout << "1";
        }
        cout << "\n";
    }

    return 0;
}