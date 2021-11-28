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
    
    n, m = map(int,input().split())

    graph = [[] for _ in range(n)]
    Kyori = [-1] * n
    Cunt = [-1] * n # 頂点iまで最短の行き方
    for _ in range(m):
        a, b = map(int,input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)
    Kyori[0] = 0
    Cunt[0] = 1

    queue = deque([0])
    while queue:
        node = queue.popleft()
        for xnode in graph[node]:
            if Kyori[xnode] < Kyori[node] + 1:
                continue
            if Kyori[xnode] == Kyori[node] + 1:
                Cunt[xnode] += 1
                continue
            # 初めて来たとき
            Kyori[xnode] = Kyori[node] + 1
            queue.append(xnode)
    print(Kyori[xnode])
    
if __name__=='__main__':
    main()