import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7
    inf = math.inf

    n = int(input())
    C = list(map(int, input().split()))
    graph = [[] for _ in range(n)]
    for _ in range(n - 1):
        a, b = map(int, input().split())
        graph[a - 1].append(b - 1)
        graph[b - 1].append(a - 1)
    ANS = []
    m = dict()
    visited = [False]*n

    def dfs(node):
        if m.get(C[node], 0) == 0:
            ANS.append(node)
        visited[node] = True
        m[C[node]] = m.get(C[node], 0) + 1
        for xnode in graph[node]:
            if not visited[xnode]:
                dfs(xnode)
        m[C[node]] -= 1
        return
    dfs(0)
    ANS.sort()
    for a in ANS:
        print(a + 1)


if __name__ == '__main__':
    main()
