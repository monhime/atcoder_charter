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

    A = list(map(int, input().split()))
    if A[0] > A[2]:
        A[0], A[2] = A[2], A[0]
    # A[0] <= A[1] <= A[2]
    if A[1] <= (A[0] + A[2])//2:
        if (A[0] + A[2]) % 2:
            x = (A[0] + A[2])//2 + 1
            print(x - A[1] + (x - (A[2] - x)) - A[0])
        else:
            print((A[0] + A[2])//2 - A[1])
    else:
        print(2*A[1] - A[0] - A[2])


if __name__ == '__main__':
    main()
