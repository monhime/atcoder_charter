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
    int h, w;
    cin >> h >> w;
    string s;

    int koma1[2] = {-1, -1};
    int koma2[2] = {-1, -1};

    for (int i = 0; i < h; i++) {
        cin >> s;
        for (int j = 0; j < w; j++){
            if (s[j] != 'o') continue;
            if (koma1[0] == -1)
            {
              koma1[0] = i;
              koma1[1] = j;
            }
            else
            {
              koma2[0] = i;
              koma2[1] = j;
              goto A;
            }
        }
    }
    A:

    // cout << koma1[0] << " " << koma1[1] << "\n";

    cout << abs(koma1[0] - koma2[0]) + abs(koma1[1] - koma2[1]) << "\n";
    return 0;
}