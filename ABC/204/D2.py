import sys, math, copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
from typing import List
# sys.setrecursionlimit(1000000)
def input(): return sys.stdin.readline().rstrip()
def main():
    mod = 10**9 + 7
    inf = 10**10
    
    n  =int(input())
    T = list(map(int,input().split()))
    sum_T = sum(T)
    dp = [[False]* (sum_T + 1) for _ in range(n + 1)] # dp[i][j] i(1-)要素目までで部分和jができるか
    dp[0][0] = True
    for i in range(n):
        for j in range(sum_T + 1):
            dp[i + 1][j] |= dp[i][j] 
            if j + T[i] <= sum_T:
                dp[i + 1][j + T[i]] |= dp[i][j]
    for j in range(-(-sum_T//2), sum_T + 1):
        if dp[n][j]:
            print(j)
            sys.exit()
    
    
if __name__=='__main__':
    main()