#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define REP(i, N) for (int i = 0; i < (int)N; i++)
#define FOR(i, a, b) for (int i = a; i < (int)b; i++)
#define ALL(x) (x).begin(), (x).end()

constexpr int MOD = 1000000007;
constexpr long long llinf = 1LL << 62;
constexpr int inf = 1LL << 30;
constexpr int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, -1, 0, 1};

using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
using vi = vector<int>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

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

int main(){
    ios::sync_with_stdio(false); //対話的出力のときはコメントアウト
    std::cin.tie(nullptr);

    string s;

    cin >> s;
    vi A(4);

    A[0] = s[0] - '0';
    A[1] = s[1] - '0';
    A[2] = s[2] - '0';
    A[3] = s[3] - '0';
    //cout << A[0] << A[1] <<"\n";

    REP(tmp, 1 << 3) {
        bitset<3> s(tmp);  //bit列の長さを予め数字で記入
        int ans = A[0];
        string ans_s = to_string(A[0]);
        REP(i, 3) {
            if (s.test(i)) { //i bit目が1なら
                ans += A[i + 1];
                ans_s +=  '+' + to_string(A[i + 1]);
            }
            else{
                ans -= A[i + 1];
                ans_s += '-' + to_string(A[i + 1]);
            }
        }
        if (ans == 7) {
            ans_s += "=7";
            cout << ans_s << "\n";
            return 0;
        }
    }

    return 0;
}
