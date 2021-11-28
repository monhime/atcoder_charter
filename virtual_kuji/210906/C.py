import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter, xor
# sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n, m = map(int, input().split())
    S = [int(input(), 2) for _ in range(n)]
    x = 1 << m - 1
    m = dict()
    ans = 0
    for s in S:
        xor_s = x ^ s
        if m.get(xor_s, 0) > 0:
            ans += m[xor_s]
        m[s] = m.get(s, 0) + 1
    print(ans)


if __name__ == '__main__':
    main()
