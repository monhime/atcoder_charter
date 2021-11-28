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

    h, w = map(int, input().split())
    S = [input() for _ in range(h)]
    ans = 0
    for i in range(h - 1):
        pre_cunt = 0
        for j in range(1, w):
            cunt = 0
            if S[i][j] == "#":
                cunt += 1
            if S[i + 1][j] == "#":
                cunt += 1
            if abs(pre_cunt - cunt) == 1:
                ans += 1
            pre_cunt = cunt
    print(ans)


if __name__ == '__main__':
    main()
