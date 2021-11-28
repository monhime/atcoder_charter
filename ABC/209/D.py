import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n, q = map(int,input().split())
    graph = [[] for _ in range(n)]
    for i in range(n - 1):
        a, b  = map(int,input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)
    
    # 木の深さ記録
    depth = [-1] * n
    depth[0] = 0
    queue = deque([0])
    while queue:
        node = queue.popleft()
        for xnode in graph[node]:
            if depth[xnode] >= 0:
                continue
            depth[xnode] = depth[node] + 1
            queue.append(xnode)
    for _ in range(q):
        c, d  = map(int,input().split())
        if abs(depth[c - 1] - depth[d - 1]) % 2:
            print("Road")
        else: 
            print("Town")


if __name__=='__main__':
    main()