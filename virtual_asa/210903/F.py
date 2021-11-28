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
    inf = 10**10
    MAX_A = 401
    MAX_B = 401

    n, m_a, m_b = map(int, input().split())
    ABC = [[int(_) for _ in input().split()] for _ in range(n)]
    dp = [[[inf]*MAX_B for _ in range(MAX_A)] for _ in range(n + 1)]
    dp[0][0][0] = 0
    for i in range(1, n + 1):
        a, b, c = ABC[i - 1]
        for j in range(MAX_A):
            for k in range(MAX_B):
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k])
                if j >= a and k >= b:
                    dp[i][j][k] = min(dp[i][j][k],
                                      dp[i - 1][j - a][k - b] + c)
    ans = inf
    for j in range(1, MAX_A):
        for k in range(1, MAX_B):
            if m_a*k == m_b * j:
                ans = min(ans, dp[n][j][k])
    if ans == inf:
        print(-1)
    else:
        print(ans)


if __name__ == '__main__':
    main()
