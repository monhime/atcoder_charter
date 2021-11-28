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
    a, b = map(int, input().split())
    ANS_a = [i + 1 for i in range(a)]
    ANS_b = [-(i + 1) for i in range(b)]
    if a < b:
        ANS_a[-1] += (b - a)*(a + b + 1)//2
    elif a > b:
        ANS_b[-1] -= (a - b)*(a + b + 1)//2
    print(" ".join(map(str, ANS_a)) + " " + " ".join(map(str, ANS_b)))


if __name__ == '__main__':
    main()
