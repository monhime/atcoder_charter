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
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    queue <Pii> que
    REP(i, N) REP(j, M) d[i][j] = INF;
    que.push(P(sx, sy));
    d[sx][sy] = 0; //INF→まだ来てない
    while(!Q.empty()){
        Pii p = que.front(); que.pop();
        if (p.first == gx && p.second == gy) break;
        for (int i = 0; i < 4; i++){
            int nx = p.first + dx[i],ny = p.second + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M && maze[nx][ny] != '#' && d[nx][ny] == INF){
                que.push(Pii(nx,ny));
                d[nx][ny] = d[p.first][p.second] + 1;
            }
        }
    }
    //bfsをつくる
    
    cin >> ;
    
    cout << << "\n";

    return 0;
}
