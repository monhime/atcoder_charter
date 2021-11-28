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
    for bit in range(1 << 4):  # 2**n通りのbit_n番目を探索
        sum_0 = 0
        sum_1 = 0
        for i in range(4):
            if (bit >> i) & 1:  # bitのi桁目が1なら
                sum_0 += A[i]
            else:
                sum_1 += A[i]
        if sum_0 == sum_1:
            print("Yes")
            break
    else:
        print("No")


if __name__ == '__main__':
    main()
