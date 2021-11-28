import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()

def scc(n, G, G_T): # n:　頂点の個数，G: 順方向の有向グラフの隣接リスト，G_T: 逆方向の有向グラフの隣接リスト
    order = [] # 記録した頂点
    visited = [0]*n
    group = [None]*n # 各頂点の属するグループ番号
    def dfs(s):
        visited[s] = 1
        for t in G[s]:
            if not visited[t]:
                dfs(t)
        order.append(s) # 帰りがけに記録
    def rdfs(s, label):
        group[s] = label # G_T上で到達できる頂点は同じグループ
        visited[s] = 1
        for t in G_T[s]:
            if not visited[t]:
                rdfs(t, label)
    for i in range(n):
        if not visited[i]:
            dfs(i) # まずG上でdfsし数字を記録
    visited = [0]*n
    label = 0 # 存在するグループ数
    for s in reversed(order): # 後に記録した頂点から
        if not visited[s]:
            rdfs(s, label) # G_T上でsからdfs
            label += 1
    return label, group 
# 縮約後のグラフを構築
def construct(n, G, label, group):
    G0 = [set() for _ in range(label)] # vの属するグループの1つ下流のグループ
    GP = [[] for _ in range(label)] # グループの要素リスト（トポロジカルソート済み）
    for v in range(n):
        lbs = group[v] # vの属するグループ
        for w in G[v]:
            lbt = group[w] # wの属するグループ
            if lbs == lbt: # 同一グループなら飛ばす
                continue
            G0[lbs].add(lbt) # 1つ下流のグループを記録
        GP[lbs].append(v) # グループの要素リストにvを追加
    return G0, GP

def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, m = map(int,input().split())
    graph = [[] for _ in range(n)]
    graph_T = [[] for _ in range(n)]
    for _ in range(m):
        a, b = map(int,input().split())
        graph[a].append(b )
        graph_T[b].append(a )

    label, group = scc(n, graph, graph_T)
    G0, GP = construct(n, graph, label, group)
    print(label)
    for gp in GP:
        print(len(gp), " ".join(map(str,gp)))
    
    
if __name__=='__main__':
    main()