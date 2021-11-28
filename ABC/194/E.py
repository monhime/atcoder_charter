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

    n, m = map(int, input().split())
    A = list(map(int, input().split()))
    dic = dict()
    for i in range(m):
        dic[A[i]] = dic.get(A[i], 0) + 1
    for a in range(n + 1):
        if dic.get(a, 0) > 0:
            continue
        else:
            mex = a
            break
    for i in range(m, n):
        dic[A[i - m]] -= 1
        dic[A[i]] = dic.get(A[i], 0) + 1
        if A[i - m] < mex and dic[A[i - m]] == 0:
            mex = A[i - m]
    print(mex)


if __name__ == '__main__':
    main()
