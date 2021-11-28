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
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n = int(input())
    X = [0]*n
    Y = [0] * n
    for i in range(n):
        x, y = map(int, input().split())
        X[i], Y[i] = x, y

    def compress2(arr): return {e: i for i, e in enumerate(sorted(set(arr)))}
    com_x = compress2(X)
    com_y = compress2(Y)
    XY = [[com_x[x], com_y[y]] for x, y in zip(X, Y)]
    print(XY)
    XY.sort()

    dp = [[0]*2001 for _ in range(2001)]
    for x, y in XY:
        dp[y][x] = 1
    dp_sum = [0]*2001
    for i in range(2001):
        x = 0
        for j in range(2001):
            x += dp[i][j]
        dp_sum[i] = x
    ans = 0
    for i in range(2000):
        for j in range(i + 1, 2001):
            if dp_sum[i] >= 2 and dp_sum[j] >= 2:
                a = min(dp_sum[i], dp_sum[j])
                ans += a*(a - 1)//2
    print(ans)


if __name__ == '__main__':
    main()
