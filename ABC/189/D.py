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
    dp = [[0, 0] for _ in range(n + 1)] # dp[i]:i番目まででyiが0or1となる場合の数
    dp[0][0] = 1
    dp[0][1] = 1
    for i in range(1, n + 1):
        s = input()
        if s =="AND":
            dp[i][0] = 2*dp[i - 1][0] + dp[i - 1][1] # xi = 0
            dp[i][1] = dp[i - 1][1] # xi = 1
        else: #OR
            dp[i][0] = dp[i - 1][0] # xi = 0
            dp[i][1] = dp[i - 1][0] + 2*dp[i - 1][1] # xi = 1
    print(dp[n][1])


    
    
if __name__=='__main__':
    main()