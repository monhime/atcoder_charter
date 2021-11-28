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


def mod_comb4(n, r, mod=10**9+7):
    if r == 1:
        return n
    elif r == 0:
        return 1
    else:
        num = reduce(lambda x, y: x*y % mod, range(n, n-r, -1))
        den = reduce(lambda x, y: x*y % mod, range(1, r+1))
        return num*pow(den, mod-2, mod) % mod


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n, s = map(int, input().split())
    A = list(map(int, input().split()))

    dp = [[0]*(s + 1) for _ in range(n + 1)]
    for i in range(n + 1):
        dp[i][0] = 1
    for i in range(n):
        for k in range(s + 1):
            if k - A[i] >= 0:
                dp[i + 1][k] = dp[i][k] + dp[i][k - A[i]]
            else:
                dp[i + 1][k] = dp[i][k]
    print(dp)
    keiro = deque()
    ans = []

    def rec(i, j):
        if i == 0:
            if j == 0:
                ans.append(copy.deepcopy(keiro))
            return
        if dp[i - 1][j]:
            rec(i - 1, j)
        if j - A[i - 1] >= 0 and dp[i - 1][j - A[i - 1]]:
            keiro.appendleft(A[i - 1])
            rec(i - 1, j - A[i - 1])
            keiro.popleft()
    rec(n, s)
    for i in range(len(ans)):
        print(i + 1, " ".join(map(str, ans[i])))
    _ans = 0
    for a in ans:
        _ans = (_ans + mod_comb4(n, len(a), mod=mod)) % mod
    print(_ans)


if __name__ == '__main__':
    main()
