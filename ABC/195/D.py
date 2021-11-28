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

    n, m, q = map(int, input().split())
    WV = [[int(_) for _ in input().split()] for i in range(n)]
    WV.sort(key=itemgetter(1), reverse=True)  # 価値の大きい順
    X = list(map(int, input().split()))
    iX = [[i + 1, x] for i, x in enumerate(X)]
    iX.sort(key=itemgetter(1))  # 箱の大きさの小さい順
    for _q in range(q):
        l, r = map(int, input().split())
        ANS = [0] * m
        Used = [False] * n
        for j, (w, v) in enumerate(WV):
            for i, x in iX:
                if i >= l and i <= r:
                    continue
                if w <= x and not ANS[i - 1] and not Used[j]:
                    ANS[i - 1] = v
                    Used[j] = True
        print(sum(ANS))


if __name__ == '__main__':
    main()
