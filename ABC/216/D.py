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

def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, m = map(int,input().split())
    graph = [[] for _ in range(n)]
    graph_T = [[] for _ in range(n)]
    for _ in range(m):
        k = int(input())
        A = list(map(int,input().split()))
        for j in range(1, k):
            if A[j - 1] == A[j]:
                print("No")
                sys.exit()
            graph[A[j - 1] - 1].append(A[j] - 1)
            graph_T[A[j] - 1].append(A[j - 1] - 1)
    
    label, _ = scc(n, graph, graph_T)
    if label == n:
        print("Yes")
    else:
        print("No")


if __name__=='__main__':
    main()