import sys, math, copy
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
    n = int(input())
    dp = [i for i in range(n + 1)]
    c_6 = 6
    while True:
        for i in range(n - c_6 + 1):
            dp[i + c_6] = min(dp[i + c_6], dp[i] + 1)
        c_6 *= 6
        if c_6 > n:
            break
    c_9 = 9
    while True:
        for i in range(n - c_9 + 1):
            dp[i + c_9] = min(dp[i + c_9], dp[i] + 1)
        c_9 *= 9
        if c_9 > n:
            break
    print(dp[n])

if __name__=='__main__':
    main()