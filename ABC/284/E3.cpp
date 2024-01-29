#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

vector<vector<int>> graph;
vector<bool> visited;
int count_paths;

void dfs(int node, int length) {
  if (visited[node]) {
    // すでに訪れたノードなら単純パスの長さをカウント
    count_paths = (count_paths + 1) % MOD;
    return;
  }

  visited[node] = true;

  // 隣接するノードに対してDFSを再帰的に実行
  for (int neighbor : graph[node]) {
    dfs(neighbor, length + 1);
  }

  visited[node] = false;
}

int main() {
  int N, M;
  cin >> N >> M;

  // グラフの初期化
  graph.resize(N + 1);
  visited.resize(N + 1, false);

  // 辺の情報を読み込み
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  count_paths = 0;
  dfs(1, 0);

  // 結果を出力
  cout << min(count_paths, 1000000) << endl;

  return 0;
}
