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
        row = 0
        for i in range(n):
            if "#" in S[i]:
                upper_flag = False
                A.append(S[i])
                row += 1
            elif not upper_flag:
                A.append(S[i])
                row += 1

        lower_flag = True
        cut_len = 0
        for i in range(row - 1, -1, -1):
            if "#" in A[i]:
                break
            cut_len += 1
        A = A[:row - cut_len]
        row -= cut_len

        left = inf
        right = 0
        for i in range(row):
            for j in range(n):
                if A[i][j] == "#":
                    left = min(left, j)
                    right = min(right, j)
        B = []
        for i in range(row):
            B.append(A[i][left:right + 1])
        return B

    print(cut(S))
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

    # +90
    no_flag = False
    for i in range(n):
        for j in range(n):
            if S[i][j] != T[-j-1][i]:
                no_flag = True
                break
        if no_flag:
            break
    else:
        print("Yes")
        sys.exit()

    # +180
    no_flag = False
    for i in range(n):
        for j in range(n):
            if S[i][j] != T[-1-i][-1-j]:
                no_flag = True
                break
        if no_flag:
            break
    else:
        print("Yes")
        sys.exit()

    # +270
    no_flag = False
    for i in range(n):
        for j in range(n):
            if S[i][j] != T[-1-j][i]:
                no_flag = True
                break
        if no_flag:
            break
    else:
        print("Yes")
        sys.exit()
    print("No")


if __name__ == '__main__':
    main()
