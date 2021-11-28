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
    n = int(input())
    A = [-1] * n
    A[0] = 1
    A[1] = 2
    idx = 2
    for i in range(n):
        if A[i] != -1:
            continue
        while idx < n:


if __name__ == '__main__':
    main()
