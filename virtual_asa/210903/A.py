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

    s = input()
    y = int(s[-1])
    if y <= 2:
        print(s[:-2]+"-")
    elif y <= 6:
        print(s[:-2])
    else:
        print(s[:-2] + "+")


if __name__ == '__main__':
    main()
