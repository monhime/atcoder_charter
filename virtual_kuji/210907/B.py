from os import initgroups
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
    TLR = [tuple(map(int, input().split())) for i in range(n)]
    TLR.sort(key=itemgetter(1))
    ans = 0
    for i in range(n - 1):
        t_1, _, r_1 = TLR[i]
        for j in range(i + 1, n):
            t_2, l_2, _ = TLR[j]
            if r_1 < l_2:
                break
            if t_1 == 1 or t_1 == 3:
                if ((t_2 == 1 or t_2 == 2) and l_2 <= r_1) or\
                        ((t_2 == 3 or t_2 == 4) and l_2 < r_1):
                    ans += 1
            else:
                if l_2 < r_1:
                    ans += 1
    print(ans)


if __name__ == '__main__':
    main()
