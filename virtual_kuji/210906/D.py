from os import initgroups
import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import index, itemgetter
# sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n = int(input())
    s = input()
    ans = 0
    for n_1 in range(10):
        for n_2 in range(10):
            for n_3 in range(10):
                if str(n_1) in s:
                    idx_1 = s.index(str(n_1))
                    s1 = s[idx_1 + 1:]
                    if str(n_2) in s1:
                        idx_2 = s1.index(str(n_2))
                        s2 = s1[idx_2 + 1:]
                        if str(n_3) in s2:
                            ans += 1
    print(ans)


if __name__ == '__main__':
    main()
