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
    D = list(map(int, input().split()))
    ans = 0
    for i in range(n - 1):
        for j in range(i + 1, n):
            ans += D[i]*D[j]
    print(ans)


if __name__ == '__main__':
    main()
