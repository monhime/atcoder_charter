#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<list>
#include<set>
#include<map>
#include<stack>
#include<deque>
#include<sstream>
#include<fstream>
//#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
typedef pair<ll, ll> P;
#define INF (1<<29)
#define INFLL (1ll<<58)
#define EPS (1e-10)
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
typedef struct edge {
    ll to, cost;
} Edge;
vector<Edge> G[2000];
ll h, w, t, d[2000], sx, sy, gx, gy;
char c[11][11];
int N=1900;

void dijkstra(int s) {
    fill(d,d+N,INFLL);
    d[s] = 0;
    priority_queue<P, vector<P>, greater<P> > que; //(<距離, 座標>)
    que.push(P(d[s], s)); //スタート地点
    
    while (!que.empty()) {
        P p = que.top(); que.pop(); //更新した中で一番距離の近いとこ
        int v=p.second; //矢先
        if (d[v] < p.first) continue; //その場所の距離が前に記録したものより大きい
        for (auto u: G[v]) {
            if (d[u.to] > d[v] + u.cost){
                d[u.to] = d[v] + u.cost; //更新
                que.push(P(d[u.to], u.to)); //更新したとこを記録
            }
        }
    }
}

void solve(){
    ll l = 0, r = 1e9, mid;
    while (r - l > 1) {
        mid = (l + r) / 2; //中間の左
        for (int i = 0;i < h;i++) {
            for (int j = 0;j < w;j++)
                G[i * 20 + j].clear(); //新しいループ毎にすべて初期化
        }
        
        for (int i = 0;i < h;i++) {
            for (int j = 0;j < w;j++) {
                for (int k = 0;k < 4;k++) { //4方向
                    int nx = i + dx[k], ny = j + dy[k];
                    if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                    
                    if (c[nx][ny] == '.' || c[nx][ny] == 'G')
                        G[i * 20 + j].push_back((Edge){ nx * 20 + ny,1 });
                    else  G[i * 20 + j].push_back((Edge){ nx * 20 + ny,mid }); //'#'の時x
                }
            }
        }
        
        dijkstra(sx*20+sy);
        if (d[gx * 20 + gy] > t)r = mid; //midが大きすぎ
        else l = mid;
    }
    cout << l << endl;
}

int main() {
    cin >> h >> w >> t;
    for (int i = 0;i < h;i++) {
        for (int j = 0;j < w;j++) {
            cin >> c[i][j];
            if (c[i][j] == 'S') sx = i, sy = j;
            if (c[i][j] == 'G') gx = i, gy = j;
        }
    }
    solve();
    
    return 0;
}
