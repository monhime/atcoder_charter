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

    s = input()
    n = len(s)
    for i in range((n - 1)//2):
        j = (n - 1)//2 - 1 - i
        # print(i, j, (n + 1)//2 + i)
        if i >= j:
            break
        if s[i] != s[j] or s[(n + 1)//2 + i] != s[-i - 1]:
            print("No")
            sys.exit()
    for i in range((n - 1)//2):
        if s[i] != s[-i - 1]:
            print("No")
            sys.exit()
    print("Yes")


if __name__ == '__main__':
    main()
