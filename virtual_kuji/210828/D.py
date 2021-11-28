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
    
    n = int(input())
    graph = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b, c  = map(int,input().split())
        graph[a - 1].append((b - 1, c))
        graph[b - 1].append((a - 1, c))
    q, k = map(int,input().split())
    k -= 1
    # 木の深さ記録
    depth = [-1] * n
    depth[k] = 0
    queue = deque([k])
    while queue:
        node = queue.popleft()
        for xnode, c in graph[node]:
            if depth[xnode] >= 0:
                continue
            depth[xnode] = depth[node] + c
            queue.append(xnode)

    for _ in range(q):
        x, y = map(int,input().split())
        print(depth[x - 1] + depth[y - 1])
    
if __name__=='__main__':
    main()