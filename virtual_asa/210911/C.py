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

    n, k = map(int, input().split())
    r, s, p = map(int, input().split())
    T = input()
    S = [""]*n  # S[i] に勝つ手を出した
    score = 0
    for i, c in enumerate(T):
        if c == "r":
            if i >= k and S[i - k] == "r":
                if i + k < n and T[i + k] == "s":
                    S[i] = "p"
                else:
                    S[i] = "s"
            else:
                S[i] = "r"
                score += p
        if c == "s":
            if i >= k and S[i - k] == "s":
                if i + k < n and T[i + k] == "p":
                    S[i] = "r"
                else:
                    S[i] = "p"
            else:
                S[i] = "s"
                score += r
        if c == "p":
            if i >= k and S[i - k] == "p":
                if i + k < n and T[i + k] == "r":
                    S[i] = "s"
                else:
                    S[i] = "r"
            else:
                S[i] = "p"
                score += s
    print(score)


if __name__ == '__main__':
    main()
