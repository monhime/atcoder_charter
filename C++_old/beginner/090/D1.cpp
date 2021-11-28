#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, M;
vector<pii> adj[100010];
int vis[100010];
ll dist[100010];

void dfs(int u) {
    vis[u] = 1;
    for(int i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i].first;
        int d = adj[u][i].second;
        if(vis[v]) continue;
        dist[v] = dist[u] + d;
        dfs(v);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < M; i++) {
        int u, v, d; scanf("%d %d %d", &u, &v, &d);
        u--; v--;
        
        adj[u].push_back(pii(v, d));
        adj[v].push_back(pii(u, -d));
    }
    
    for(int i = 0; i < N; i++) if(!vis[i]) {
        dist[i] = 0;
        dfs(i);
    }
    
    for(int u = 0; u < N; u++) {
        for(int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i].first;
            int d = adj[u][i].second;
            
            if(dist[v] != dist[u] + d) {
                printf("No");
                return 0;
            }
        }
    }
    printf("Yes");
}
