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
    inf = math.inf
    n, m = map(int, input().split())
    graph = [[] for _ in range(n)]
    for _ in range(m):
        a, b, c = map(int, input().split())
        graph[a - 1].append((b - 1, c))

    dp = [[inf]*n for _ in range(n)]
    lis_max = [[-1]*n for _ in range(n)]
    for i in range(n):
        dp[i][i] = 0
    for s in range(n):
        queue = [(0, s)]
        while queue:
            dist, node = heappop(queue)
            if dist > dp[s][node]:  # 既に早い時刻に更新されていた場合
                continue
            for xnode, c in graph[node]:
                x_t = dp[s][node] + c
                if x_t >= dp[s][xnode]:
                    continue
                heappush(queue, (x_t, xnode))
                dp[s][xnode] = x_t
                if node == s:
                    lis_max[s][xnode] = 0
                else:
                    lis_max[s][xnode] = max(node, lis_max[s][node])
    print(dp)
    print(lis_max)
    ans = 0
    for s in range(n):
        for t in range(n):
            if dp[s][t] > 0 and lis_max[s][t] >= 0:
                ans += dp[s][t]*(n - lis_max[s][t])
    print(ans)


if __name__ == '__main__':
    main()
