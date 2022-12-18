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
    int n;
    cin >> n;
    vi A(n);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int p = 0;
    vi B(4, 0);
    for (int i = 0; i < n; i++)
    {
        B[0] = 1;
        for (int j = 1; j <= A[i]; j++) {
          p += B[4 - j];
        }
        for (int j = 3; j >= A[i]; j--)
        {
          B[j] = B[j - A[i]];
        }
        for (int j = A[i] - 1; j >= 0; j--)
        {
          B[j] = 0;
        }
    }
    cout << p << "\n";

    return 0;
}