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
    dp = [[0]*w for _ in range(h)]  # 高橋-青木
    for i in range(h):
        for j in range(w):
            if (i + j) % 2:
                if A[i][j] == "+":
                    if i == 0 and j > 0:
                        dp[i][j] = dp[i][j - 1] + 1
                    if j == 0 and i > 0:
                        dp[i][j] = dp[i - 1][j] + 1
                    if i > 0 and j > 0:
                        dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j - 1] + 1)
                else:
                    if i == 0 and j > 0:
                        dp[i][j] = dp[i][j - 1] - 1
                    if j == 0 and i > 0:
                        dp[i][j] = dp[i - 1][j] - 1
                    if i > 0 and j > 0:
                        dp[i][j] = max(dp[i - 1][j] - 1, dp[i][j - 1] - 1)
            else:
                if A[i][j] == "+":
                    if i == 0 and j > 0:
                        dp[i][j] = dp[i][j - 1] - 1
                    if j == 0 and i > 0:
                        dp[i][j] = dp[i - 1][j] - 1
                    if i > 0 and j > 0:
                        dp[i][j] = min(dp[i - 1][j] - 1, dp[i][j - 1] - 1)
                else:
                    if i == 0 and j > 0:
                        dp[i][j] = dp[i][j - 1] + 1
                    if j == 0 and i > 0:
                        dp[i][j] = dp[i - 1][j] + 1
                    if i > 0 and j > 0:
                        dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1)

            print(dp)
    if dp[h - 1][w - 1] > 0:
        print("Takahashi")
    elif dp[h - 1][w - 1] == 0:
        print("Draw")
    else:
        print("Aoki")


if __name__ == '__main__':
    main()
