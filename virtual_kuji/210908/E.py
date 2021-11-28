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

    q = int(input())
    L = [True]*(10**5 + 1)
    L[0], L[1] = False, False
    for i in range(2, int(10**2.5) + 1):
        if not L[i]:
            continue
        x = i**2
        k = i
        while x <= 10**5:
            L[x] = False
            k += 1
            x = i*k
    ANS = [0] * (10**5 + 1)  # iは条件を満たすか
    for i in range(10**5 + 1):
        if L[i] and L[(i + 1)//2]:
            ANS[i] = 1
    ANS = list(accumulate(ANS))
    for _ in range(q):
        l, r = map(int, input().split())
        print(ANS[r] - ANS[l - 1])


if __name__ == '__main__':
    main()
