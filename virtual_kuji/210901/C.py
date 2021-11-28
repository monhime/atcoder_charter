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

    n, s = input().split()
    n = int(n)
    length = 2
    ans = 0
    while length <= n:
        m = dict()
        for i in range(length):
            m[s[i]] = m.get(s[i], 0) + 1
        if (m.get("C", 0)*m.get("G", 0) > 0 or m.get("A", 0)*m.get("T", 0) > 0) \
                and (m.get("C", 0) == m.get("G", 0) and m.get("A", 0) == m.get("T", 0)):
            ans += 1
        for i in range(length, n):
            m[s[i]] = m.get(s[i], 0) + 1
            m[s[i - length]] -= 1
            if (m.get("C", 0)*m.get("G", 0) > 0 or m.get("A", 0)*m.get("T", 0) > 0) \
                    and (m.get("C", 0) == m.get("G", 0) and m.get("A", 0) == m.get("T", 0)):
                ans += 1
        length += 2
    print(ans)


if __name__ == '__main__':
    main()
