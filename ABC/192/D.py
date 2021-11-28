import sys
import math
import copy
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
    inf = float('inf')

    n, m, x, y = map(int, input().split())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b, t, k = map(int, input().split())
        graph[a - 1].append((b - 1, t, k))
        graph[b - 1].append((a - 1, t, k))

    queue = [(0, x - 1)]
    ans = [inf] * n
    ans[x - 1] = 0
    while queue:
        dist, node = heappop(queue)
        if dist > ans[node]:  # 既に早い時刻に更新されていた場合
            continue
        for xnode, t, k in graph[node]:
            x_t = -(-(ans[node])//k)*k + t
            if x_t >= ans[xnode]:
                continue
            heappush(queue, (x_t, xnode))
            ans[xnode] = x_t
    if ans[y - 1] == inf:
        print(-1)
    else:
        print(ans[y - 1])


if __name__ == '__main__':
    main()
