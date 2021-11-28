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
    inf = math.inf

    l, q = map(int, input().split())
    lis = []
    len_lis = 0
    for _ in range(q):
        c, x = map(int, input().split())
        if c == 1:
            lis.append(x)
            len_lis += 1
            lis.sort()
        else:

            idx = bisect_left(lis, x)
            if idx >= len_lis:
                if len_lis == 0:
                    print(l)
                else:
                    print(l - lis[idx - 1])
            else:
                if idx == 0:
                    print(lis[0])
                else:
                    print(lis[idx] - lis[idx - 1])


if __name__ == '__main__':
    main()
