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

    h, w = map(int, input().split())
    A = [input() for _ in range(h)]
    _A = [[1 if c == "+" else -1 for c in a] for a in A]
    dp = [[0]*w for _ in range(h)]  # 高橋-青木
    for i in range(h - 1, -1, -1):
        for j in range(w - 1, -1, -1):
            if (i + j) % 2 == 0:
                if i == h - 1 and j + 1 < w:
                    dp[i][j] = dp[i][j + 1] + _A[i][j + 1]
                if j == w - 1 and i + 1 < h:
                    dp[i][j] = dp[i + 1][j] + _A[i + 1][j]
                if i + 1 < h and j + 1 < w:
                    dp[i][j] = max(dp[i + 1][j] + _A[i + 1][j],
                                   dp[i][j + 1] + _A[i][j + 1])
            else:
                if i == h - 1 and j + 1 < w:
                    dp[i][j] = dp[i][j + 1] - _A[i][j + 1]
                if j == w - 1 and i + 1 < h:
                    dp[i][j] = dp[i + 1][j] - _A[i + 1][j]
                if i + 1 < h and j + 1 < w:
                    dp[i][j] = min(dp[i + 1][j] - _A[i + 1][j],
                                   dp[i][j + 1] - _A[i][j + 1])
    if dp[0][0] > 0:
        print("Takahashi")
    elif dp[0][0] == 0:
        print("Draw")
    else:
        print("Aoki")


if __name__ == '__main__':
    main()
