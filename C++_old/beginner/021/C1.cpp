#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// {この頂点への最短距離, この頂点の番号} を管理する構造体
struct P {
    int dist, num;
    // デフォルト(大きい値が先頭)
    bool operator<(const P &p) const {
        return dist < p.dist;
    }
    // greater(小さい値が先頭)
    bool operator>(const P &p) const {
        return dist > p.dist;
    }
};

vector<vector<int>> G;
const int mod = 1e9+7;
const int INF = 1e8;
int N, a, b, M;
int dist[111]; // dist[i]: aからiまでの最短距離
ll cnt[111]; // cnt[i]: aからiまで最短距離で来る個数

void dijkstra(int s) {
    // 初期化
    fill(dist, dist + N, INF);
    dist[s] = 0;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.push({0, s});
    cnt[s] = 1; // いつもと違って、経路数を求める配列があるのでそれも初期化する
    
    while (Q.size()) {
        P p = Q.top(); Q.pop();
        int v = p.num; // 今見ている頂点
        if (dist[v] < p.dist) continue;
        for (int t : G[v]) {
            if (dist[t] > dist[v] + 1) {
                dist[t] = dist[v] + 1;
                Q.push({dist[t], t});//エラーの可能性
            }
            // 今見ている頂点が最短経路上にあるならば、前の頂点からのカウントを足し合わせる
            if (dist[t] == dist[v] + 1) {
                cnt[t] += cnt[v];
            }
        }
    }
}

int main() {
    // 入力
    cin >> N >> a >> b >> M;
    a--, b--;
    G = vector<vector<int>>(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    
    // ダイクストラ法
    dijkstra(a);
    
    // 出力
    cout << cnt[b] % mod << endl;
    
    return 0;
}
