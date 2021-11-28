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

    S = ["ABC", "ARC", "AGC", "AHC"]
    SS = [input()for _ in range(3)]
    for s in S:
        if not s in SS:
            print(s)
            sys.exit()


if __name__ == '__main__':
    main()
