import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter, ne
sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n = int(input())
    graph = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = map(int,input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)

    visited = [False] * n
    route = []
    def dfs(n):
        route.append(n + 1)
        visited[n] = True
        for next in sorted(graph[n]):
            if visited[next]:
                continue
            visited[next] = True
            dfs(next)
            route.append(n + 1)
    dfs(0)
    print(" ".join(map(str, route)))

if __name__=='__main__':
    main()