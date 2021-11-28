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
    ABC = [tuple(map(int, input().split())) for i in range(m)]

    dp = [[inf]*n for _ in range(n)]  # dp[k][j][i]: i->jで最大k
    for i in range(n):
        dp[i][i] = 0
    for a, b, c in ABC:
        dp[a - 1][b - 1] = c
    ans = 0

    for k in range(n):
        xdp = [[0]*n for _ in range(n)]
        for i in range(n):
            for j in range(n):
                xdp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j])
                if xdp[i][j] < inf:
                    ans += xdp[i][j]
        dp = xdp
    print(ans)


if __name__ == '__main__':
    main()
