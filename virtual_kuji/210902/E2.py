import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7
    inf = 10**10

    n = int(input())
    A = list(map(int, input().split()))

    cunt = 0

    def merge_cunt(A):
        len_A = len(A)
        if len_A <= 1:
            return 0
        cunt_x = 0
        B = A[:len_A//2]
        C = A[len_A//2:]

        cunt_x += merge_cunt(B)
        cunt_x += merge_cunt(C)

        ai, bi, ci = 0, 0, 0

        while ai < len_A:
            if bi < len_A//2 and (ci == len_A - len_A//2 or B[bi] <= C[ci]):
                A[ai] = B[bi]
                ai += 1
                bi += 1
            else:
                cunt_x += len_A//2 - bi
                A[ai] = C[ci]
                ai += 1
                ci += 1
        return cunt_x
    A_c = copy.deepcopy(A)
    cunt = merge_cunt(A_c)
    print(cunt)
    for k in range(n - 1):
        cunt += n - 1 - 2*A[k]
        print(cunt)


if __name__ == '__main__':
    main()
