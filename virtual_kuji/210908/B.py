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

    n = int(input())
    X = list(map(int, input().split()))
    abs_X = [abs(x) for x in X]
    print(sum(abs_X))
    ans = 0.0
    for x in abs_X:
        ans += x**2
    print(math.sqrt(ans))
    print(max(abs_X))


if __name__ == '__main__':
    main()
