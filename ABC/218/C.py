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
    S = [input() for _ in range(n)]
    T = [input() for _ in range(n)]

    def cut(L):
        A = []
        upper_flag = True
        for i in range(n):
            if "#" in S[i]:
                upper_flag = True
                A.append(S[i])
            elif not upper_flag:
                A.append(S[i])
        return A

    no_flag = False
    for i in range(n):
        for j in range(n):
            if S[i][j] != T[i][j]:
                no_flag = True
                break
        if no_flag:
            break
    else:
        print("Yes")
        sys.exit()


if __name__ == '__main__':
    main()
