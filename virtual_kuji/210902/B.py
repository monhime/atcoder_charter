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

    a, b = map(int, input().split())
    s = input()
    for c in s[:a]+s[b + 1:]:
        if c < "0" or c > "9":
            print("No")
            sys.exit()
    if s[a] != "-":
        print("No")
    else:
        print("Yes")


if __name__ == '__main__':
    main()
