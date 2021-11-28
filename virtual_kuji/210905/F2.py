from functools import reduce
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
    mod = 998244353
    inf = math.inf

    n, s = map(int, input().split())
    A = list(map(int, input().split()))

    dp = [[0]*(s + 1) for _ in range(n + 1)]
    dp[0][0] = 1
    for i in range(1, n + 1):
        for k in range(s + 1):
            dp[i][k] = (dp[i][k] + dp[i - 1][k] * 2) % mod
            if k - A[i - 1] >= 0:
                dp[i][k] = (dp[i][k] + dp[i - 1][k - A[i - 1]]) % mod
    print(dp[n][s])


if __name__ == '__main__':
    main()
