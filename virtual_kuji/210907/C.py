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
    S = [int(input())for _ in range(n)]
    dp = [[False]*(n*max(S) + 1)for _ in range(n + 1)]
    dp[0][0] = True
    for i in range(n + 1):
        for j in range(n*max(S) + 1):
            dp[i][j] |= dp[i - 1][j]  # 不正解
            if j >= S[i - 1]:
                dp[i][j] |= dp[i - 1][j - S[i - 1]]
    for i in range(n*max(S), -1, -1):
        if i % 10 and dp[n][i]:
            print(i)
            break
    else:
        print(0)


if __name__ == '__main__':
    main()
