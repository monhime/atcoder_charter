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

    s = int(input())
    m = dict()
    i = 1
    while True:
        if m.get(s, -1) == 1:
            print(i)
            sys.exit()
        m[s] = 1
        if s % 2 == 0:
            s = s // 2
        else:
            s = 3*s + 1
        i += 1


if __name__ == '__main__':
    main()
