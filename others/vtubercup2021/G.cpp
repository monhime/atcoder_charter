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

    int n;
    cin >> n;
    vi V(n);
    REP(i, n) cin >> V[i];
    sort(ALL(V));

    priority_queue<double> PQ;
    for (auto &v: V){
        PQ.emplace(-v);
    }
    while (!PQ.empty()){
        double pq_1 = PQ.top(); PQ.pop();
        if (PQ.empty()){
            cout << -pq_1 <<"\n";
            break;
        }
        double pq_2 = PQ.top(); PQ.pop();
        PQ.emplace((double)(pq_1 + pq_2)/2);
    }

    return 0;
}
