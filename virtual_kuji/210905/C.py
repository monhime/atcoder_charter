from os import initgroups
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

    n = int(input())
    S = [input() for _ in range(n)]
    dp = [[0]*2 for _ in range(n + 1)]  # dp[i][j]: i番目まででFase or True
    dp[0][1] = 1
    dp[0][0] = 1
    for i in range(1, n + 1):
        if S[i - 1] == "AND":
            dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1]
            dp[i][1] = dp[i - 1][1]
        else:
            dp[i][0] = dp[i - 1][0]
            dp[i][1] = 2 * dp[i - 1][1] + dp[i - 1][0]
    print(dp[n][1])


if __name__ == '__main__':
    main()
