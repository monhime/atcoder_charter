import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


def main():
    mod = 10**9 + 7  # 998244353
    inf = math.inf

    h, w, a, b = map(int, input().split())
    # 長さ2を先に埋めて残りを1x1で埋める
    used = [[False]*w for _ in range(h)]
    global ans
    ans = 0

    def rec(i, j, cunt):
        global ans
        if i == h - 1 and j == w - 1:
            if cunt == a:
                ans += 1
            return
        if cunt > a:
            return
        if used[i][j]:  # 次のマスへ
            if j + 1 < w:
                rec(i, j + 1, cunt)
            elif i + 1 < h:
                rec(i + 1, 0, cunt)
        else:
            if j + 1 < w:
                rec(i, j + 1, cunt)  # 使わない
            elif i + 1 < h:
                rec(i + 1, 0, cunt)
            # 横におく
            if j + 1 < w and not used[i][j + 1]:
                used[i][j], used[i][j + 1] = True, True
                rec(i, j + 1, cunt + 1)
                used[i][j], used[i][j + 1] = False, False
            # 縦におく
            if i + 1 < h and not used[i + 1][j]:
                used[i][j], used[i + 1][j] = True, True
                if j + 1 < w:
                    rec(i, j + 1, cunt + 1)
                else:
                    rec(i + 1, 0, cunt + 1)
                used[i][j], used[i + 1][j] = False, False
    rec(0, 0, 0)
    print(ans)


if __name__ == '__main__':
    main()
