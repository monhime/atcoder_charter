#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// 座標(y, x)を管理
struct P { ll y, x; };

// (最短距離, 座標)の情報
struct V {
    ll dist;
    P pos;
    // デフォルト
    bool operator>(const V &t) const {
        return dist > t.dist;
    }
    // greater
    bool operator<(const V &t) const {
        return dist < t.dist;
    }
};

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

const ll MAX = 1e9;
const ll INF = 1e15;
int H, W; // 高さ、幅
ll T; // 制限時間
int sy, sx, gy, gx; // スタート座標、ゴール座標
char B[50][50]; // 盤面の文字の情報
ll dist[50][50]; // 盤面の距離の情報

// ダイクストラ法で距離を求める。cは'#'のコスト
ll dijkstra(ll c) {
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) dist[i][j] = INF;
    dist[sy][sx] = 0;
    priority_queue<V, vector<V>, greater<V>> Q;
    Q.push({0, P{sy, sx}});
    
    while (Q.size()) {
        V v = Q.top(); Q.pop();
        int y = v.pos.y, x = v.pos.x;
        if (dist[y][x] < v.dist) continue;
        // 隣接頂点を調べる代わりに隣接マスを調べる
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            ll cost = B[ny][nx]=='.' ? 1LL : c;
            if (dist[ny][nx] > dist[y][x] + cost) {
                dist[ny][nx] = dist[y][x] + cost;
                Q.push( V{dist[ny][nx], P{ny, nx}} );
            }
        }
    }
}

// 2分探索でxを決め打つ
ll bin() {
    auto check = [&](ll x) -> bool {
        dijkstra(x); // ダイクストラで距離を計算
        return dist[gy][gx] <= T;
    };
    
    // [l, r)の半開区間
    ll l = 1, r = T+1;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        if (check(m)) {
            l = m;
        } else {
            r = m;
        }
    }
    
    return l;
}

int main() {
    // 入力
    cin >> H >> W >> T;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> B[i][j];
            if (B[i][j] == 'S') {
                sy = i, sx = j;
                B[i][j] = '.';
            }
            if (B[i][j] == 'G') {
                gy = i, gx = j;
                B[i][j] = '.';
            }
        }
    }
    
    // 処理はbin関数に丸投げ
    cout << bin() << endl;
    
    return 0;
}
