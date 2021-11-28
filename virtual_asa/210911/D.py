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

    n, m = map(int, input().split())
    A = [int(input())for _ in range(m)]
    d = deque()
    for a in A:
        d.appendleft(a)
    m = dict()
    ANS = []
    while d:
        x = d.popleft()
        if m.get(x, 0) == 0:
            ANS.append(x)
        m[x] = 1
    for i in range(1, n + 1):
        if m.get(i, 0) == 0:
            ANS.append(i)
    print("\n".join(map(str, ANS)))


if __name__ == '__main__':
    main()
