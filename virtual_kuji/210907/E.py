import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
from functools import cmp_to_key
# sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    n, q = map(int, input().split())
    sq = int(math.sqrt(q))
    C = list(map(int, input().split()))
    C = [c - 1 for c in C]
    LR = [[int(_) for _ in input().split()] for i in range(q)]
    LR = [[l - 1, r] for l, r in LR]
    Idx = [i for i in range(q)]

    def hilbertorder(x, y):
        print(x, y)
        d = 0
        s = 1 << 20 - 1
        while s:
            rx, ry = bool(x & s), bool(y & s)
            d = d << 2 | rx*3 ^ int(ry)
            if ry:
                continue
            if rx:
                x = 1 << 20 - x
                y = 1 << 20 - x
            x, y = y, x
            s >>= 1
        return d
    Ord = [hilbertorder(l, r) for l, r in LR]

    def cmp(a, b):  # 横軸l，縦軸r，横軸方向をsq個に分割
        return Ord[a] - Ord[b]
    Idx.sort(key=cmp_to_key(cmp))

    cur_l, cur_r = 0, 0
    global cunt
    cunt = 0
    m = dict()
    ANS = [0]*q

    def add(x):
        global cunt
        if m.get(C[x], 0) == 0:
            cunt += 1
        m[C[x]] = m.get(C[x], 0) + 1

    def delet(x):
        global cunt
        m[C[x]] = m.get(C[x], 0) - 1
        if m.get(C[x], 0) == 0:
            cunt -= 1

    for i in range(q):
        xl, xr = LR[Idx[i]]
        while cur_l > xl:
            cur_l -= 1
            add(cur_l)
        while cur_l < xl:
            delet(cur_l)
            cur_l += 1
        while cur_r < xr:
            add(cur_r)
            cur_r += 1
        while cur_r > xr:
            cur_r -= 1
            delet(cur_r)
        ANS[Idx[i]] = cunt
    print("\n".join(map(str, ANS)))


if __name__ == '__main__':
    main()
