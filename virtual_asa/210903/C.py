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
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    if sum(A) <= k:
        ans = 0
        for a in A:
            ans += a*(a+1)//2
        print(ans)
        sys.exit()

    def f(x):
        # 最大値をxにするのに必要な回数
        cunt = 0
        for a in A:
            cunt += max(a - x, 0)
        return cunt

    left = 0
    right = max(A)
    while right - left > 1:
        mid = (left + right)//2
        if f(mid) > k:  # oooxxxx
            left = mid
        else:
            right = mid
    ans = 0
    cunt_x = 0
    for a in A:
        if a >= right + 1:
            ans += (a - right)*(a + right + 1)//2
            cunt_x += a - right
    print(ans + (k - cunt_x)*right)


if __name__ == '__main__':
    main()
