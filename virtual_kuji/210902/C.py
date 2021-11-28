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
    D = list(map(int, input().split()))
    m = map(int, input().split())
    T = list(map(int, input().split()))

    m = dict()
    for d in D:
        m[d] = m.get(d, 0) + 1
    for t in T:
        if m.get(t, 0) == 0:
            print("NO")
            sys.exit()
        m[t] -= 1
    print("YES")


if __name__ == '__main__':
    main()
